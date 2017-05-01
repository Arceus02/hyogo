#include "FightingUnit.h"


FightingUnit::FightingUnit(const FightingUnitData &unitData, Vect2D position)
		: Unit(unitData.asset,
			   unitData.name,
			   unitData.maxHp,
			   unitData.viewRange,
			   unitData.speed),
		  damage(unitData.damage),
		  attackRange(unitData.attackRange) {
	this->position = position;
}

int FightingUnit::getDamage() {
	return damage;
}

int FightingUnit::getAttackRange() {
	return attackRange;
}