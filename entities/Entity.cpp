#include "Entity.h"

Entity::Entity(std::string pathToAsset,
			   int maxHp,
			   int viewRange)
		: pathToAsset(pathToAsset),
		  maxHp(maxHp),
		  hp(maxHp),
		  viewRange(viewRange),
		  position(Vect2D(0, 0)) {}

void Entity::draw(Buffer buffer, Vect2D viewOffset) {
	// TODO draw entity from asset
}

void Entity::setPosition(Vect2D position) {
	this->position = position;
}

Vect2D Entity::getPosition() {
	return position;
}
