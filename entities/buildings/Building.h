#pragma once


#include "../Entity.h"


class Building : public Entity {
protected:
	int level, maxLevel;
public :
	Building(AssetId assetId, std::string name, int maxHp, int maxLevel);

	virtual bool canLevelUp();

	void levelUp();

	int getLevel();
};
