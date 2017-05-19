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

void Unit::setCanWalkThroughRiver(bool canWalkThroughRiver) {
	this->canWalkThroughRiver = canWalkThroughRiver;
}

bool Unit::getCanWalkThroughRiver() {
	return canWalkThroughRiver;
}

const int Unit::getSpeed() const {
    return speed;
}

void Unit::setFinishedTurn(bool setFinishedTurn) {
    this->finishedTurn = finishedTurn;
}

const bool Unit::getFinishedTurn() const {
    return finishedTurn;
}
