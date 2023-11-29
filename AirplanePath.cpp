#include "AirplanePath.h"
#include <queue>
#include <set>

AirplanePath::AirplanePath(TerrainMap& m, Point start_in, Point finish_in)
    : Path(m, "AirplanePath", start_in, finish_in) {}

struct Node {
    Point position;
    double cost;
    double heuristic;
    Node* parent;

    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

bool AirplanePath::find() {
    std::priority_queue<Node> open_set;
    std::set<Point> closed_set;

    open_set.push({start, 0.0, 0.0, nullptr});

    while (!open_set.empty()) {
        Node current = open_set.top();
        open_set.pop();

        if (current.position == finish) {
            while (current.parent != nullptr) {
                path.push_back(current.position);
                current = *current.parent;
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return true;
        }

        closed_set.insert(current.position);

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;

                Point neighbor = current.position + Point(i, j);
                if (!map.validCoords(neighbor) || closed_set.count(neighbor) > 0) continue;

                double cost = current.cost + 1.0;
                double heuristic = (neighbor - finish).length();
                open_set.push({neighbor, cost + heuristic, heuristic, new Node(current)});
            }
        }
    }

    return false;
}

