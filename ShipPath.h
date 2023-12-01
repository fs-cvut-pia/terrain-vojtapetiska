#ifndef SHIP_PATH_H
#define SHIP_PATH_H

#include "Path.h"

class ShipPath : public Path {
public:
    ShipPath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    bool find() override;
};

#endif



