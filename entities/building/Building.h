#pragma once


#include "../Entity.h"


class Building : public Entity {
private:
    int level;

public :
    Building(std::string pathToAsset,std::string name, int maxHp);
    virtual bool canLevelUp();
    void levelUp();
    int getLevel();
};
