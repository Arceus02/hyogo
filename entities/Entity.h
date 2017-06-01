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
    bool finishedTurn = false;
    Player owner;
public:
    Entity(AssetId assetId, const std::string &name, EntityType type, int maxHp, int viewRange);

    virtual ~Entity();

    virtual void
    draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Player currentTurn) const = 0;

    void drawSelectionBox(const Vect2D &viewOffset) const;

    void drawIsFinishedTurnBox(const Vect2D &viewOffset) const;

    void setPosition(const Vect2D &position);

    const Vect2D &getPosition() const;

    EntityType getType() const;

    void setFinishedTurn(bool finishedTurn);

    const bool isFinishedTurn() const;

    void setOwner(Player player);

    const Player getOwner() const;

    const std::string getName() const;

    const int getHP() const;

    const AssetId getAssetId()const;
};
