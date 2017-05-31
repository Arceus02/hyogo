#include "FightingUnit.h"


FightingUnit::FightingUnit(const FightingUnitData &unitData, const Vect2D &position)
		: Unit(unitData.assetId,
			   unitData.name,
               FIGHTINGUNIT,
			   unitData.maxHp,
			   unitData.viewRange,
			   unitData.speed),
		  damage(unitData.damage),
		  attackRange(unitData.attackRange) {
	this->position = position;
    if(unitData.assetId == UNIT_SCOUT){
        setCanWalkThroughRiver(true);
    }
}
FightingUnit::~FightingUnit(){}

const int FightingUnit::getDamage() const {
	return damage;
}

const int FightingUnit::getAttackRange() const {
	return attackRange;
}
