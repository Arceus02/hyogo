#pragma once

#include <string>
#include "../util/Vect2D.h"
#include "../util/Asset.h"
#include "../util/const.h"
#include "../util/ResourceManager.h"

enum Player {
	PLAYER1, PLAYER2
};

class Entity {
protected:
	std::string name;
	AssetId assetId;
	int maxHp, hp;
	int viewRange;
	Vect2D position;
	Player player;
public:
	Entity(AssetId assetId, const std::string &name, int maxHp, int viewRange);

	void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset) const;

	void setPosition(const Vect2D &position);

	const Vect2D &getPosition() const;
};