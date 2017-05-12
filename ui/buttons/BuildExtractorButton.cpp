#include "BuildExtractorButton.h"

BuildExtractorButton::BuildExtractorButton():UIComponent(96,25,
                                                         Vect2D(MAP_VIEW_WIDTH-20-2*96,MAP_VIEW_HEIGHT+15+50)){}

void BuildExtractorButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_BUILD_EXTRACTOR).draw(position);
}
