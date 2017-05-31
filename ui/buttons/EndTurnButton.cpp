#include "EndTurnButton.h"

EndTurnButton::EndTurnButton() : UIComponent(155, 35, Vect2D(10, WINDOW_HEIGHT - 7 - 35)) {}

void EndTurnButton::draw(const ResourceManager &resourceManager) const {
    resourceManager.getResource(UI_END_TURN_BUTTON).draw(position);
}
