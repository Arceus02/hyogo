#pragma once


#include "../Entity.h"
#include "../units/Unit.h"

class Building : public Entity {
protected:
    int level, maxLevel;
    Unit *garnison;
public :
    Building(AssetId assetId, std::string name, int maxHp, int maxLevel);

    bool canLevelUp();

    void levelUp();

    int getLevel();

    Unit *getGarnisonUnit();
};