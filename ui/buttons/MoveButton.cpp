#include "MoveButton.h"

MoveButton::MoveButton(): UIComponent(BUTTON_WIDTH,BUTTON_HEIGHT,
                                      Vect2D(MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 6)){}

void MoveButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_MOVE_BUTTON).draw(position);
}
Action MoveButton::getAction()const{
    return MOVE;
}
