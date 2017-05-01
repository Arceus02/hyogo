#pragma once


#include "Entity.h"

class BuyableEntity : public Entity {
public:
	BuyableEntity(const Asset &asset, std::string name, int maxHp, int viewRange);
};