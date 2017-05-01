#include "DefenseTurret.h"

DefenseTurret::DefenseTurret():
    Building("/assets/buildings/defenseturret.png","Defense Turret",15){}

bool DefenseTurret::canLevelUp(){
	return level <= 1;
}


