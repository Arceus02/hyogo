#include "AttackButton.h"

AttackButton::AttackButton() : UIComponent(157, 41,
                                           Vect2D(MAP_VIEW_WIDTH - 157 - 10, MAP_VIEW_HEIGHT + 12 + 41)) {

}
void AttackButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_ATTACK_BUTTON).draw(position);
}
