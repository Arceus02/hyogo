#include "DefenseTurret.h"

DefenseTurret::DefenseTurret() : Building(INCONSTRUCTION_TURRET, "Defense Turret", 15, 2) {}

void DefenseTurret::build(){
    isUnderConstruction = false;
    assetId = BUILDING_TURRET;
}
