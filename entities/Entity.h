#pragma once


#include <string>
#include "../util/Vect2D.h"
#include "../util/Buffer.h"

enum PLAYERS {
	PLAYER1, PLAYER2
};

class Entity {
protected:
	std::string pathToAsset;
	int maxHp, hp;
	int viewRange;
	Vect2D position;
	// TODO add team
public:
	Entity(std::string pathToAsset, int maxHp, int viewRange);

	void draw(Buffer buffer, Vect2D viewOffset);

	void setPosition(Vect2D position);

	Vect2D getPosition();
};




