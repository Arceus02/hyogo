#include "Building.h"

Building::Building(AssetId assetId, std::string name, int maxHp, int maxLevel)
        : Entity(assetId, name,BUILDING, maxHp, 4), level(1), maxLevel(1) {}

void Building::levelUp() {
	level++;
}

int Building::getLevel() {
	return level;
}

bool Building::canLevelUp() {
	return level < maxLevel;
}
