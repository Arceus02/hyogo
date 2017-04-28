#pragma once

#include "Building.h"

class CommandCenter : public Building{
public:
    CommandCenter();
    virtual canLevelUp();
    bool winGame();
};
