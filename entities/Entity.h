#pragma once


#include <string>
#include "../util/Vect2D.h"
#include "../util/Buffer.h"
#include "../util/Asset.h"

enum Player {
	PLAYER1, PLAYER2
};

class Entity {
protected:
	std::string pathToAsset;
    std::string name;
	const Asset *asset;
	int maxHp, hp;
	int viewRange;
	Vect2D position;
    Player player;
	// TODO add team
public:
	Entity(const Asset &asset, std::string name, int maxHp, int viewRange);

	void draw(Buffer &buffer, Vect2D viewOffset);

	void setPosition(Vect2D position);

	Vect2D getPosition();
};