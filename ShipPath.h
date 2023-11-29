// ShipPath.h

#ifndef SHIPPATH_H
#define SHIPPATH_H

#include "Path.h"

class ShipPath : public Path {
public:
    ShipPath(TerrainMap& m, Point start_in, Point finish_in);
    bool find() override;
};

#endif

