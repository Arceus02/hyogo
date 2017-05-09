#pragma once

#include "../Unit.h"

// Fighting units
struct FightingUnitData {
	std::string name;
    EntityType type;
	AssetId assetId;
	int maxHp, viewRange, speed, damage, attackRange;

	FightingUnitData(std::string name,
					 AssetId assetId,
					 int maxHp,
					 int viewRange,
					 int speed,
					 int damage,
					 int attackRange)
			: name(name),
			  assetId(assetId),
			  maxHp(maxHp),
			  viewRange(viewRange),
			  speed(speed),
			  damage(damage),
			  attackRange(attackRange) {
		// TODO add costs
	}
};

namespace FightingUnits {
	const FightingUnitData SCOUT = FightingUnitData("Scout", UNIT_SCOUT, 3, 12, 6, 2, 1);
	const FightingUnitData INFANTRY_MELEE = FightingUnitData("Infantry Melee", UNIT_INFANTRY_MELEE, 6, 6, 3, 4, 1);
	const FightingUnitData INFANTRY_DISTANCE = FightingUnitData("Infantry Distance", UNIT_INFANTRY_DISTANCE, 2, 8, 3, 6,
																4);
	const FightingUnitData CAVALRY = FightingUnitData("Cavalry", UNIT_CAVALRY, 6, 8, 5, 4, 1);
	const FightingUnitData HEAVY = FightingUnitData("Heavy", UNIT_HEAVY, 7, 4, 2, 7, 2);
	const FightingUnitData BALLISTIC = FightingUnitData("Ballistic", UNIT_BALLISTIC, 4, 6, 1, 5, 7);
};

class FightingUnit : public Unit {
private:
	int damage;
	int attackRange;
public:
	FightingUnit(const FightingUnitData &unitData, const Vect2D &position);

	const int getDamage() const;

	const int getAttackRange() const;
};
