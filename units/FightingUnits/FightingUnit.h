#pragma once
#include "../Unit.h"

class FightingUnit : public Unit{
private:
    int damage;
    int attackRange;
public:
    FightingUnit(int hp, int speed, int viewRange, int mineralCost, int gasCost, int damage, int attackRange);
};
