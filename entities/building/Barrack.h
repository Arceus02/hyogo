#pragma once

#include "Building.h"

class Barrack : public Building {
public:
    Barrack();
    virtual bool canLevelUp();

};