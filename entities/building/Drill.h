#pragma once

#include "Building.h"

class Drill : public Building{
public:
    Drill();
    virtual bool canLevelUp();
    int getProduction();
};
