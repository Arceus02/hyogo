#pragma once


#include "../BuyableEntity.h"
#include "../../map/Map.h"

class Unit : public BuyableEntity {
protected:
	int speed;
	bool canWalkThroughRiver = false;
public:
    Unit(std::string pathToAsset,std::string name, int maxHp, int viewRange, int speed);

	// TODO verify movement
	void move(Vect2D movement);

	void setCanWalkThroughRiver(bool canWalkThroughRiver);

	bool getCanWalkThroughRiver();

	virtual int getSpeedOn(TerrainType terrainType) = 0;
};
