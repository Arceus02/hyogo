#include "Entity.h"

Entity::Entity(AssetId assetId, const std::string &name, EntityType type, int maxHp, int viewRange, int turnNumberToBeBuilt)
        : assetId(assetId),
          name(name),
          type(type),
          maxHp(maxHp),
          hp(maxHp),
          viewRange(viewRange),
          position(Vect2D(0, 0)),
          turnNumberToBeBuilt(turnNumberToBeBuilt){}

Entity::~Entity(){}

void Entity::drawSelectionBox(const Vect2D &viewOffset) const {
    AlphaColor c(0, 0, 255, 100);
    Vect2D renderPosition = position * MAP_SQUARE_PIXEL_SIZE + viewOffset;
    Imagine::fillRect(renderPosition.x(), renderPosition.y(), MAP_SQUARE_PIXEL_SIZE, MAP_SQUARE_PIXEL_SIZE, c);
}

void Entity::drawIsFinishedTurnBox(const Vect2D &viewOffset) const {
    AlphaColor c(255, 0, 0, 100);
    Vect2D renderPosition = position * MAP_SQUARE_PIXEL_SIZE + viewOffset;
    Imagine::fillRect(renderPosition.x(), renderPosition.y(), MAP_SQUARE_PIXEL_SIZE, MAP_SQUARE_PIXEL_SIZE, c);
}

void Entity::setPosition(const Vect2D &position) {
    this->position = position;
}

const Vect2D &Entity::getPosition() const {
    return position;
}

EntityType Entity::getType() const {
    return type;
}

void Entity::setFinishedTurn(bool finishedTurn) {
    this->finishedTurn = finishedTurn;
}

const bool Entity::isFinishedTurn() const {
    return finishedTurn;
}

void Entity::setOwner(Player player) {
    owner = player;
}

const Player Entity::getOwner() const {
    return owner;
}
const std::string Entity::getName() const{
    return name;
}
const int Entity::getHP() const{
    return hp;
}
const AssetId Entity::getAssetId()const{
    return assetId;
}
const int Entity::getTurnNumberToBeBuilt()const{
    return turnNumberToBeBuilt;
}
void Entity::build(){
    if(turnNumberToBeBuilt !=0){
        turnNumberToBeBuilt--;
    }
}
