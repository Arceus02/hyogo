#pragma once

#include <string>
#include "../util/Vect2D.h"
#include "../util/Asset.h"
#include "../util/const.h"
#include "../util/ResourceManager.h"


class Entity {
protected:
    std::string name;
    AssetId assetId;
    EntityType type;
    int maxHp, hp;
    int viewRange;
    Vect2D position;

public:
    Entity(AssetId assetId, const std::string &name, EntityType type, int maxHp, int viewRange);

    void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset) const;

    void drawSelectionBox(const Vect2D &viewOffset) const;

    void setPosition(const Vect2D &position);

    const Vect2D &getPosition() const;

    EntityType getType() const;

};
