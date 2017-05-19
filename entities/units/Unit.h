#pragma once


#include "../Entity.h"
#include "../../map/Map.h"
#include <vector>

class Unit : public Entity {
protected:
    int speed;
    bool canWalkThroughRiver = false;
    std::vector<Vect2D> possibleMoves;
public:
    Unit(AssetId assetId, std::string name, EntityType type, int maxHp, int viewRange, int speed);

    void drawPossibleMoves(Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) const;

    void setCanWalkThroughRiver(bool canWalkThroughRiver);

    bool getCanWalkThroughRiver();

    const int getSpeed() const;

    void setPossibleMoves(std::vector<Vect2D> &possibleMoves);

    const bool isPossibleMove(const Vect2D &position) const;
};
