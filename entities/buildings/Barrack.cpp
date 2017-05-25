#include "Barrack.h"

Barrack::Barrack() : Building(INCONSTRUCTION_BARRACK, "Barrack", 30, 3) {}

void Barrack::build(){
    isUnderConstruction = false;
    assetId = BUILDING_BARRACK;
}
