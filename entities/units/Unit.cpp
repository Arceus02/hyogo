#include "Unit.h"

Unit::Unit(std::string pathToAsset,
		   int maxHp,
		   int viewRange,
		   int speed)
		: BuyableEntity(pathToAsset,
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