#include "Fightingunit.h"

FightingUnit::FightingUnit (int hp, int speed, int viewRange, int mineralCost, int gasCost, int damage, int attackRange) :Unit(hp,speed,viewRange,mineralCost,gasCost), damage(damage), attackRange(attackRange){}
