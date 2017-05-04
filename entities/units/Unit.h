#pragma once


#include "../Entity.h"
#include "../../map/Map.h"

class Unit : public Entity {
protected:
	int speed;
	bool canWalkThroughRiver = false;
public:
	Unit(AssetId assetId, std::string name, int maxHp, int viewRange, int speed);

	// TODO verify movement
	void move(Vect2D movement);

	void setCanWalkThroughRiver(bool canWalkThroughRiver);

	bool getCanWalkThroughRiver();
};