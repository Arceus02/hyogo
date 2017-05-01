#include "Building.h"

Building::Building(std::string pathToAsset, std::string name, int maxHp) :
            Entity(pathToAsset,name,maxHp,1),level(1){}

void Building::levelUp(){
    level++;
}

int Building::getLevel(){
    return level;
}

bool Building::canLevelUp() {
	return false;
}