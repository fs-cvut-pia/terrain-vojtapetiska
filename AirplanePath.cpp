#include "AirplanePath.h"

AirplanePath::AirplanePath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool AirplanePath::find() {
    // Implementace skuteèného algoritmu pro nalezení cesty letadlem
    // Tato implementace je pouze ilustrativní, musíte ji nahradit skuteèným algoritmem

    int dx = finish.x - start.x;
    int dy = finish.y - start.y;

    if (std::abs(dx) > std::abs(dy)) {
        int step = (dx > 0) ? 1 : -1;
        for (int x = start.x; x != finish.x; x += step) {
            path.push_back({x, start.y});
        }
    } else {
        int step = (dy > 0) ? 1 : -1;
        for (int y = start.y; y != finish.y; y += step) {
            path.push_back({start.x, y});
        }
    }

    // Pøidání koncového bodu
    path.push_back(finish);

    return true;
}
