#include "UnitIconButton.h"

UnitIconButton::UnitIconButton(const Vect2D &position): UIComponent(25,25,position){}

void UnitIconButton::draw(const ResourceManager &resourceManager) const{
    AssetId correspondingAsset = resourceManager.correspondingIcon(iconAssetId);
    resourceManager.getResource(correspondingAsset).draw(position);
    if (unit->isFinishedTurn() || unit->getTurnNumberToBeBuilt() > 0) {
        AlphaColor c(255, 0, 0, 30);
        Imagine::fillRect(position, 25, 25, c);
    }
}

void UnitIconButton::setUnit(Unit *unit) {
    this->unit = unit;
    this->iconAssetId = unit->getAssetId();
}