#include "RecruitButton.h"

RecruitButton::RecruitButton(): UIComponent(132,41,
                                      Vect2D(MAP_VIEW_WIDTH - 132 -10,MAP_VIEW_HEIGHT  + 12 + 41)){}

void RecruitButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_RECRUIT_BUTTON).draw(position);
}
