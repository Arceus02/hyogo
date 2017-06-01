#include "UIComponent.h"


UIComponent::UIComponent(const int width, const int height, const Vect2D &position) :
        width(width), height(height), position(position), activated(false) {
}
UIComponent::~UIComponent(){}

Vect2D UIComponent::getPosition() const {
	return position;
}

const bool UIComponent::isActivated() const {
    return activated;
}

void UIComponent::setActivated(bool activate) {
    activated = activate;
}

Vect2D UIComponent::getSize() const {
    return Vect2D(width, height);
}

void UIComponent::setIconAssetId(AssetId assetId){}
