#pragma once
#include "../Unit.h"

// TODO enum all unit data

class FightingUnit : public Unit {
private:
    int damage;
    int attackRange;
public:
	FightingUnit(std::string pathToAsset, int maxHp, int viewRange, int speed, int damage, int attackRange,
				 Vect2D position);

	int getDamage();

	int getAttackRange();
};