#include "Building.h"

Building::Building(AssetId assetId, std::string name, int maxHp, int maxLevel, int turnNumberToBeBuilt, int maxGarrison)
        : Entity(assetId, name,BUILDING, maxHp, 4,turnNumberToBeBuilt), level(1), maxLevel(maxLevel),
         maxGarrison(maxGarrison){}

Building::~Building(){}

void Building::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset) const {
    Vect2D renderPosition = position * MAP_SQUARE_PIXEL_SIZE + viewOffset;
    resourceManager.getResource(assetId).draw(renderPosition);
    AlphaColor c = (owner == PLAYER1) ? ACYAN : AMAGENTA;
    Imagine::drawRect(renderPosition, MAP_SQUARE_PIXEL_SIZE - 1, MAP_SQUARE_PIXEL_SIZE - 1, c);
    if(turnNumberToBeBuilt >=1){
        AlphaColor c2(255,0,0,100);
        Imagine::fillRect(renderPosition.x(), renderPosition.y(), MAP_SQUARE_PIXEL_SIZE, MAP_SQUARE_PIXEL_SIZE, c2);
    }
}
void Building::levelUp() {
	level++;
}

const int Building::getLevel() const {
	return level;
}

bool Building::canLevelUp(int mineralQuantity, int gasQuantity) const {
    return level < maxLevel && turnNumberToBeBuilt ==0 && mineralQuantity >= UPGRADE_MINERAL_COST.at(assetId).at(level-1)
            && gasQuantity >= UPGRADE_GAS_COST.at(assetId).at(level-1);
}
const int Building::getMaxlevel()const{
    return maxLevel;
}
Unit *Building::getGarrisonUnit(int number) const{
    return garrison[number];
}

void Building::addGarrisonUnit(Unit &garrison){
    assert(this->garrison.size() <= maxGarrison);
    this->garrison.push_back(&garrison);
    garrison.setInGarrison(true);
}
void Building::removeUnitGarrison(AssetId assetId){
    for(std::vector<Unit*>::iterator it = garrison.begin();it!=garrison.end();++it){
        if((*it)->getAssetId() == assetId){
            garrison.erase(it);
            break;
        }
    }
}
const std::vector<Unit*> Building::getGarrison()const{
    return garrison;
}
const int Building::getMaxGarrison()const{
    return maxGarrison;
}
const int Building::getGarrisonSize()const{
    return garrison.size();
}

