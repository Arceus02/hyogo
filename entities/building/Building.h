#pragma once


#include "../Entity.h"


class Building : public Entity {
protected:
    int level;
public :
    Building(std::string pathToAsset,std::string name, int maxHp);
    virtual bool canLevelUp();
    void levelUp();
    int getLevel();
};
