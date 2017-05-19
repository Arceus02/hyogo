#pragma once

#include <vector>
#include "pointDist.h"

class FilePriorite {
    std::vector<PointDist> v;
public:
    FilePriorite();

    bool empty() const;

    void push(PointDist d);

    PointDist pop();
};
