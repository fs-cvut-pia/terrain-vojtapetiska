#include "AirplanePath.h"
#include <queue>
#include <set>

AirplanePath::AirplanePath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool AirplanePath::find() {
    // Implementace hledání cesty pro letadlo (Dijkstrův algoritmus)
    std::priority_queue<std::pair<int, Point>, std::vector<std::pair<int, Point>>, std::greater<>> pq;
    std::set<Point> visited;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, current] = pq.top();
        pq.pop();

        if (visited.count(current) > 0) {
            continue;
        }

        path.push_back(current);
        visited.insert(current);

        if (current == finish) {
            break;
        }

        // Získání možných sousedních bodů
        std::vector<Point> neighbors = {
            {current.x + 1, current.y},
            {current.x - 1, current.y},
            {current.x, current.y + 1},
            {current.x, current.y - 1}
        };

        for (const auto& neighbor : neighbors) {
            if (map.validCoords(neighbor)) {
                int altitude = map.alt(neighbor);
                int newCost = cost + 1;  // Předpokládáme, že každý krok má stejnou cenu

                // Pokud je výška na následujícím poli nižší, přidáme ho do fronty
                if (altitude < map.alt(current)) {
                    pq.push({newCost, neighbor});
                }
            }
        }
    }

    return true;
}
