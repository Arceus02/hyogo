#include "Unit.h"

Unit::Unit(AssetId assetId,
           std::string name,
           EntityType type,
           int maxHp,
           int viewRange,
           int speed)
		: Entity(assetId,
				 name,
                 type,
				 maxHp,
				 viewRange),
		  speed(speed) {}

void Unit::move(Vect2D movement) {
	this->position += movement;
}

void Unit::setCanWalkThroughRiver(bool canWalkThroughRiver) {
	this->canWalkThroughRiver = canWalkThroughRiver;
}

bool Unit::getCanWalkThroughRiver() {
	return canWalkThroughRiver;
}
