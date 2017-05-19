#pragma once


#include "../Entity.h"
#include "../../map/Map.h"

class Unit : public Entity {
protected:
    int speed;
    bool canWalkThroughRiver = false;
    bool finishedTurn;
public:
    Unit(AssetId assetId, std::string name, EntityType type, int maxHp, int viewRange, int speed);

    void setCanWalkThroughRiver(bool canWalkThroughRiver);

    bool getCanWalkThroughRiver();

    const int getSpeed() const;

    void setFinishedTurn(bool finishedTurn);

    const bool getFinishedTurn() const;
};
