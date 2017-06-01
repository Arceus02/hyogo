#include "UnitIconButton.h"

UnitIconButton::UnitIconButton(const Vect2D &position): UIComponent(25,25,position){}

void UnitIconButton::draw(const ResourceManager &resourceManager) const{
    AssetId correspondingAsset = resourceManager.correspondingIcon(iconAssetId);
    resourceManager.getResource(correspondingAsset).draw(position);
}

void UnitIconButton::setIconAssetId(AssetId assetId){
    iconAssetId = assetId;
}
