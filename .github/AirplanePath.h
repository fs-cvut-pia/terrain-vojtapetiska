#ifndef AIRPLANE_PATH_H
#define AIRPLANE_PATH_H

#include "Path.h" // Přidáno pro dědičnost

class AirplanePath : public Path {
public:
    AirplanePath(TerrainMap& m, Point start_in, Point finish_in);
    bool find() override; // Implementace metody find pro letadlo
};

#endif
