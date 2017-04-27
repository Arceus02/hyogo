#pragma once


#include "Entity.h"

class BuyableEntity : public Entity {
public:
	BuyableEntity(std::string pathToAsset, int maxHp, int viewRange);
};