#include "DefenseTurret.h"

DefenseTurret::DefenseTurret():
    Building("/assets/buildings/defenseturret.png","Defense Turret",15){}

bool DefenseTurret::canLevelUp(){
    if(level <=1)
        return true;
    return false;
}


