#include "EndTurnButton.h"

EndTurnButton::EndTurnButton() : UIComponent(157, 41, Vect2D(10, MAP_VIEW_HEIGHT + 12 + 41)) {}

void EndTurnButton::draw(const ResourceManager &resourceManager) const {
    resourceManager.getResource(UI_END_TURN_BUTTON).draw(position);
}