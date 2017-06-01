#include "FightingUnit.h"


FightingUnit::FightingUnit(const FightingUnitData &unitData, const Vect2D &position)
        : Unit(unitData.assetId,
               unitData.name,
               FIGHTINGUNIT,
			   unitData.maxHp,
			   unitData.viewRange,
               unitData.speed,
               unitData.turnNumberToBeBuilt),
		  damage(unitData.damage),
		  attackRange(unitData.attackRange) {
	this->position = position;
    if(unitData.assetId == UNIT_SCOUT){
        setCanWalkThroughRiver(true);
    }
}

FightingUnit::~FightingUnit() {}

const int FightingUnit::getDamage() const {
    return damage;
}

const int FightingUnit::getAttackRange() const {
    return attackRange;
}

void FightingUnit::setPossibleAttacks(std::vector<Vect2D> &possibleAttacks) {
    this->possibleAttacks = possibleAttacks;
}

const bool FightingUnit::isPossibleAttack(const Vect2D &position) {
    for (std::vector<Vect2D>::iterator k = possibleAttacks.begin(); k != possibleAttacks.end(); k++) {
        Vect2D &v = *k;
        if (v.x() == position.x() && v.y() == position.y()) {
            return true;
        }
    }
    return false;
}

void FightingUnit::drawPossibleAttacks(Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) const {
    AlphaColor c(255, 0, 0, 30);
    for (std::vector<Vect2D>::const_iterator k = possibleAttacks.begin(); k != possibleAttacks.end(); k++) {
        Vect2D p = (*k);
        if (inside(p, minRender, maxRender)) {
            Vect2D renderPosition = p * MAP_SQUARE_PIXEL_SIZE + viewOffset;
            Imagine::fillRect(renderPosition.x(), renderPosition.y(), MAP_SQUARE_PIXEL_SIZE, MAP_SQUARE_PIXEL_SIZE, c);
        }
    }
}
