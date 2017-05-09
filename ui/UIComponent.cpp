#include "UIComponent.h"


UIComponent::UIComponent(const int width,const int height,const Vect2D &position) :
    width(width), height(height), position(position), activated(false){
}

void UIComponent::setPosition(const Vect2D &position) {
	this->position = position;
}

Vect2D UIComponent::getPosition() const {
	return position;
}

void UIComponent::setWidth(int width) {
	this->width;
}

void UIComponent::setHeight(int height) {
	this->height;
}

int UIComponent::getWidth() {
	return width;
}

int UIComponent::getHeight() {
	return height;
}
void UIComponent::draw(const ResourceManager &resourceManager) const{

}
Action UIComponent::getAction()const{

}

void UIComponent::setBorderColor(const Imagine::AlphaColor &color) {
	borderColor = color;
}

void UIComponent::setFillColor(const Imagine::AlphaColor &color) {
	fillColor = color;
}
bool UIComponent::isActivated()const{
    return activated;
}
void UIComponent::setActivated(bool activate){
    activated = activate;
}
