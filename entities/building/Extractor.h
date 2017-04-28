#pragma once

#include "Building.h"

class Extractor : public Building{
private:
    int gasProduction;
public:
    Extractor();
    virtual bool canLevelUp();
    int getProduction();
};
