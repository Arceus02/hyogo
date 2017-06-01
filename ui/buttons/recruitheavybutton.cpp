#include "RecruitHeavyButton.h"

RecruitHeavyButton::RecruitHeavyButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+2+64)){}

void RecruitHeavyButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_HEAVY).draw(position);
}
