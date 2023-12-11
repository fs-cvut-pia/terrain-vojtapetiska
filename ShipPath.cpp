// ShipPath.cpp
#include "ShipPath.h"
#include <queue>
#include <set>
#include <cmath>

ShipPath::ShipPath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool ShipPath::find() {
    // Implementace hledání cesty pro loď (podmínky pro nadmořskou výšku < 0)
    std::priority_queue<std::pair<double, Point>, std::vector<std::pair<double, Point>>, std::greater<>> pq;
    std::set<Point> visited;
    Matrix<Point> prev(map.nx, map.ny);

    auto heuristic = [this](const Point& a, const Point& b) {
        // Jednoduchá heuristika - Eukleidovská vzdálenost
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    };

    pq.push({heuristic(start, finish), start});
    visited.insert(start);

    while (!pq.empty()) {
        auto [cost, current] = pq.top();
        pq.pop();

        if (current == finish) {
            // Pokud jsme dosáhli cíle, rekonstruujeme cestu
            while (current != start) {
                path.push_back(current);
                current = prev(current);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());

            return true;
        }

        // Definice možných směrů
        std::vector<Point> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
        };

        for (const auto& direction : directions) {
            Point neighbor = current + direction;

            if (map.validCoords(neighbor) && (map.alt(neighbor) < 0 || neighbor == finish) && visited.count(neighbor) == 0) {
                pq.push({cost + heuristic(neighbor, finish), neighbor});
                visited.insert(neighbor);
                prev(neighbor) = current;
            }
        }
    }

    // Pokud dojde k tomu, že priority queue je prázdná a cíl není dosažen, vrátíme false
    return false;
}



