#pragma once


#include <vector>
#include "UIComponent.h"
#include "../util/ResourceManager.h"

class UIManager {
private:
	std::vector<UIComponent> components;
public:
	UIManager();

	void draw(const ResourceManager &resourceManager) const;
};