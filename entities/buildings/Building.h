#pragma once


#include "../Entity.h"
#include "../units/Unit.h"

class Building : public Entity {
protected:
    int level, maxLevel;
    int maxGarrison;
    std::vector<Unit *> garnison;
public :
    Building(AssetId assetId, std::string name, int maxHp, int maxLevel, int turnNumberToBeBuilt, int maxGarrison);

    virtual ~Building();

    void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Player currentTurn) const;

    bool canLevelUp(int mineralQuantity, int gasQuantity)const;

    void levelUp();

    const int getLevel()const;

    const int getMaxlevel()const;

    Unit *getGarrisonUnit(int number) const;

    void addGarnisonUnit(Unit *garnison);

    void removeUnitGarrison(AssetId assetId);

    const std::vector<Unit*> getGarrison()const;

    const int getMaxGarrison()const;

    const int getGarrisonSize()const;

    const int getTurnNumberToBeBuilt() const;

    void build();
};
