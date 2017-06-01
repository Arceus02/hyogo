#include "RecruitWorkerButton.h"

RecruitWorkerButton::RecruitWorkerButton(): UIComponent(132,41,
                                      Vect2D(MAP_VIEW_WIDTH - 132 -10,MAP_VIEW_HEIGHT  + 6 )){}

void RecruitWorkerButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_RECRUIT_WORKER).draw(position);
}
