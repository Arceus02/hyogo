#pragma once


#include "Entity.h"

class BuyableEntity : public Entity {
public:
    BuyableEntity(std::string pathToAsset, std::string name, int maxHp, int viewRange);
};
