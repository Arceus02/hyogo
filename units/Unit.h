#pragma once


class Unit {
private:
    int hp;
    int speed;
    int viewRange;
    int mineralCost;
    int gasCost;
public:
    Unit(int hp, int speed, int viewRange, int mineralCost, int gasCost);
};
