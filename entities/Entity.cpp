#include "Entity.h"

Entity::Entity(AssetId assetId, const std::string &name, EntityType type, int maxHp, int viewRange)
		: assetId(assetId),
		  name(name),
          type(type),
		  maxHp(maxHp),
		  hp(maxHp),
		  viewRange(viewRange),
		  position(Vect2D(0, 0)) {}

void Entity::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset) const {
	Vect2D renderPosition = position * MAP_SQUARE_PIXEL_SIZE + viewOffset;
	resourceManager.getResource(assetId).draw(renderPosition);
}

void Entity::setPosition(const Vect2D &position) {
	this->position = position;
}

const Vect2D &Entity::getPosition() const {
	return position;
}
EntityType Entity::getType()const{
    return type;
}
