#include "Entity.h"

Entity::Entity(const Asset &asset,
			   std::string name,
			   int maxHp,
			   int viewRange)
		: asset(&asset),
		  name(name),
		  maxHp(maxHp),
		  hp(maxHp),
		  viewRange(viewRange),
		  position(Vect2D(0, 0)) {}

void Entity::draw(Buffer &buffer, Vect2D viewOffset) {
	Vect2D renderPosition = position * MAP_SQUARE_PIXEL_SIZE + viewOffset;
	asset->draw(buffer, renderPosition);
}

void Entity::setPosition(Vect2D position) {
	this->position = position;
}

Vect2D Entity::getPosition() {
	return position;
}
