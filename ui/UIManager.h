#pragma once


#include <vector>
#include "UIComponent.h"
#include "buttons/AttackButton.h"
#include "buttons/BuildButton.h"
#include "buttons/MoveButton.h"
#include "../util/const.h"
#include "../util/ResourceManager.h"
#include "../stores/BuildingStore.h"
#include "../stores/UnitStore.h"


class UIManager {
private:
    std::map<Action,UIComponent*> components;
public:
	UIManager();

	void draw(const ResourceManager &resourceManager) const;


    void clickActionButton(const Vect2D position, Action &action);

    void displayButton(EntityType type);

    void clearUi();
};
