#include "ShipPath.h"

ShipPath::ShipPath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool ShipPath::find() {
    // Implementace hled�n� cesty pro lo�
    Point current = start;

    while (current != finish) {
        path.push_back(current);

        // Z�sk�n� mo�n�ch sousedn�ch bod�
        std::vector<Point> neighbors = {
            {current.x + 1, current.y},
            {current.x - 1, current.y},
            {current.x, current.y + 1},
            {current.x, current.y - 1}
        };

        Point next;
        int minAltitude = std::numeric_limits<int>::max();

        for (const auto& neighbor : neighbors) {
            if (map.validCoords(neighbor)) {
                int altitude = map.alt(neighbor);
                if (altitude < minAltitude) {
                    minAltitude = altitude;
                    next = neighbor;
                }
            }
        }

        // Pokud v��ka na n�sleduj�c�m poli je nez�porn�, skon��me hled�n�
        if (minAltitude >= 0) {
            break;
        }

        current = next;
    }

    // P�id�n� c�lov�ho bodu do cesty
    path.push_back(finish);

    return true;
}

