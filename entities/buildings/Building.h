#pragma once


#include "../Entity.h"
#include "../units/Unit.h"

class Building : public Entity {
protected:
    int level, maxLevel;
    Unit *garnison;
    bool isUnderConstruction;
public :
    Building(AssetId assetId, std::string name, int maxHp, int maxLevel);

    bool canLevelUp();

    void levelUp();

    int getLevel();

    Unit *getGarnisonUnit() const;

    void setGarnisonUnit(Unit *garnison);

    virtual void build();
};
