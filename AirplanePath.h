#ifndef AIRPLANE_PATH_H
#define AIRPLANE_PATH_H

#include "Path.h"

class AirplanePath : public Path {
public:
    AirplanePath(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);

    virtual bool find() override;
};

#endif
