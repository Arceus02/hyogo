#include "UIComponent.h"


UIComponent::UIComponent(int width, int height) : width(width), height(height), position(Vect2D(0, 0)) {
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

void UIComponent::draw() const {
	return;
}

void UIComponent::setBorderColor(const Imagine::AlphaColor &color) {
	borderColor = color;
}

void UIComponent::setFillColor(const Imagine::AlphaColor &color) {
	fillColor = color;
}
