#include "MoveButton.h"

MoveButton::MoveButton(): UIComponent(157,41,
                                      Vect2D(MAP_VIEW_WIDTH - 157 -10,MAP_VIEW_HEIGHT  + 6)){}

void MoveButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_MOVE_BUTTON).draw(position);
}
