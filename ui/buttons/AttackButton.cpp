#include "AttackButton.h"

AttackButton::AttackButton():UIComponent(BUTTON_WIDTH,BUTTON_HEIGHT,
                                          Vect2D(MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 12 + BUTTON_HEIGHT)){}
void AttackButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_ATTACK_BUTTON).draw(position);
}
Action AttackButton::getAction()const{
    return ATTACK;
}
