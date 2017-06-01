#pragma once

#include "../Unit.h"

// Fighting units
struct FightingUnitData {
    std::string name;
    EntityType type;
	AssetId assetId;
    int maxHp, viewRange, speed, damage, attackRange, turnNumberToBeBuilt;

	FightingUnitData(std::string name,
					 AssetId assetId,
					 int maxHp,
					 int viewRange,
					 int speed,
					 int damage,
                     int attackRange,
                     int turnNumberToBeBuilt)
			: name(name),
			  assetId(assetId),
			  maxHp(maxHp),
			  viewRange(viewRange),
			  speed(speed),
			  damage(damage),
              attackRange(attackRange),
              turnNumberToBeBuilt(turnNumberToBeBuilt){
		// TODO add costs
	}
};

namespace FightingUnits {
    const FightingUnitData SCOUT = FightingUnitData("Scout", UNIT_SCOUT, 3, 12, 6, 2, 1,1);
    const FightingUnitData INFANTRY_MELEE = FightingUnitData("Infantry Melee", UNIT_INFANTRY_MELEE, 6, 6, 3, 4, 1,1);
    const FightingUnitData INFANTRY_DISTANCE = FightingUnitData("Infantry Distance", UNIT_INFANTRY_DISTANCE, 2, 8, 3, 6,
                                                                4,2);
    const FightingUnitData CAVALRY = FightingUnitData("Cavalry", UNIT_CAVALRY, 6, 8, 5, 4, 1,2);
    const FightingUnitData HEAVY = FightingUnitData("Heavy", UNIT_HEAVY, 7, 4, 2, 7, 2,3);
    const FightingUnitData BALLISTIC = FightingUnitData("Ballistic", UNIT_BALLISTIC, 4, 6, 1, 5, 7,3);
};

class FightingUnit : public Unit {
private:
    int damage;
    int attackRange;
    std::vector<Vect2D> possibleAttacks;
public:

    FightingUnit(const FightingUnitData &unitData, const Vect2D &position);

    ~FightingUnit();

    const int getDamage() const;

    const int getAttackRange() const;

    void setPossibleAttacks(std::vector<Vect2D> &possibleAttacks);

    const bool isPossibleAttack(const Vect2D &position);

    void drawPossibleAttacks(Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) const;
};
