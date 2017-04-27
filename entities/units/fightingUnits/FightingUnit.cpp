#include "FightingUnit.h"

FightingUnit::FightingUnit(std::string pathToAsset,
						   int maxHp,
						   int viewRange,
						   int speed,
						   int damage,
						   int attackRange,
						   Vect2D position)
		: Unit(pathToAsset,
			   maxHp,
			   viewRange,
			   speed),
		  damage(damage),
		  attackRange(attackRange) {
	this->position = position;
}

int FightingUnit::getDamage() {
	return damage;
}

int FightingUnit::getAttackRange() {
	return attackRange;
}
