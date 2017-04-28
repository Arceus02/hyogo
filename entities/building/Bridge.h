#pragma once

#include "Building.h"

class Bridge : public Building{
public:
    Bridge();
    virtual bool canLevelUp();
};
