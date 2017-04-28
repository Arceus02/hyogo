#pragma once

#include "../Unit.h"

// Fighting units
struct FightingUnitData {
    std::string pathToAsset, name;
	int maxHp, viewRange, speed, damage, attackRange;

	FightingUnitData(std::string pathToAsset,
                     std::string name,
					 int maxHp,
					 int viewRange,
					 int speed,
					 int damage,
					 int attackRange)
			: pathToAsset(pathToAsset),
              name(name),
			  maxHp(maxHp),
			  viewRange(viewRange),
			  speed(speed),
			  damage(damage),
			  attackRange(attackRange) {}
};

namespace FightingUnits {
    FightingUnitData SCOUT = FightingUnitData("/assets/units/scout.png","Scout", 3, 12, 6, 2, 1);
    FightingUnitData INFANTRY_MELEE = FightingUnitData("/assets/units/infantry_melee.png","Infantery Melee", 6, 6, 3, 4, 1);
    FightingUnitData INFANTRY_DISTANCE = FightingUnitData("/assets/units/infantry_distance.png","Infantery Distance", 2, 8, 3, 6, 4);
    FightingUnitData CAVALRY = FightingUnitData("/assets/units/cavalry.png","Cavalry", 6, 8, 5, 4, 1);
    FightingUnitData HEAVY = FightingUnitData("/assets/units/heavy.png","Heavy", 7, 4, 2, 7, 2);
    FightingUnitData BALLISTIC = FightingUnitData("/assets/units/ballistic.png","Ballistic", 4, 6, 1, 5, 7);
}

class FightingUnit : public Unit {
private:
	int damage;
	int attackRange;
public:
	FightingUnit(FightingUnitData unitData, Vect2D position);

	int getDamage();

	int getAttackRange();
};
