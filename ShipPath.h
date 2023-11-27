#ifndef SHIP_PATH_H
#define SHIP_PATH_H

#include "Path.h" // Přidáno pro dědičnost

class ShipPath : public Path {
public:
    ShipPath(TerrainMap& m, Point start_in, Point finish_in);
    bool find() override; // Implementace metody find pro loď
};

#endif
