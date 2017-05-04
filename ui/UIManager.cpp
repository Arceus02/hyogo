#include "UIManager.h"
#include "../util/const.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};

UIManager::UIManager() {

}

void UIManager::draw(const ResourceManager &resourceManager) const {
	resourceManager.getResource(UI_PANEL_BOTTOM).draw(PANEL_BOTTOM_POSITION);
	for (std::vector<UIComponent>::const_iterator k = components.begin(); k != components.end(); k++) {
		(*k).draw();
	}
}
