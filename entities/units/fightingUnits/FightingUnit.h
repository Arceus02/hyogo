#pragma once

#include "../Unit.h"
#include "../../../util/Asset.h"

// Fighting units
struct FightingUnitData {
	std::string pathToAsset, name;;
	Asset asset;
	int maxHp, viewRange, speed, damage, attackRange;

	FightingUnitData(std::string pathToAsset,
                     std::string name,
					 int maxHp,
					 int viewRange,
					 int speed,
					 int damage,
					 int attackRange)
			: pathToAsset(pathToAsset),
			  asset(pathToAsset),
			  name(name),
			  maxHp(maxHp),
			  viewRange(viewRange),
			  speed(speed),
			  damage(damage),
			  attackRange(attackRange) {
		// TODO add costs
	}
};

namespace FightingUnits {
	const FightingUnitData SCOUT = FightingUnitData(srcPath("assets/units/scout.png"), "Scout", 3, 12, 6, 2, 1);
	const FightingUnitData INFANTRY_MELEE = FightingUnitData(srcPath("assets/units/infantry_melee.png"),
															 "Infantry Melee", 6, 6, 3, 4, 1);
	const FightingUnitData INFANTRY_DISTANCE = FightingUnitData(srcPath("assets/units/infantry_distance.png"),
																"Infantry Distance", 2, 8, 3, 6, 4);
	const FightingUnitData CAVALRY = FightingUnitData(srcPath("assets/units/cavalry.png"), "Cavalry", 6, 8, 5, 4, 1);
	const FightingUnitData HEAVY = FightingUnitData(srcPath("assets/units/heavy.png"), "Heavy", 7, 4, 2, 7, 2);
	const FightingUnitData BALLISTIC = FightingUnitData(srcPath("assets/units/ballistic.png"), "Ballistic", 4, 6, 1, 5,
														7);
};

class FightingUnit : public Unit {
private:
	int damage;
	int attackRange;
public:
	FightingUnit(const FightingUnitData &unitData, Vect2D position);

	int getDamage();

	int getAttackRange();
};