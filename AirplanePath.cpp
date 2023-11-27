#include "AirplanePath.h"

AirplanePath::AirplanePath(TerrainMap& m, Point start_in, Point finish_in)
    : Path(m, "AirplanePath", start_in, finish_in) {}

bool AirplanePath::find() {
    // Implementace algoritmu pro nalezení nejkratší cesty pro letadlo
    return false;
}
