#include "EndTurnButton.h"

EndTurnButton::EndTurnButton() : UIComponent(155, 35, Vect2D(10, MAP_VIEW_HEIGHT + 33)) {}

void EndTurnButton::draw(const ResourceManager &resourceManager) const {
    resourceManager.getResource(UI_END_TURN_BUTTON).draw(position);
}
