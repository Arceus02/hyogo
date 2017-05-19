#pragma once


#include <vector>
#include "UIComponent.h"
#include "buttons/AttackButton.h"
#include "buttons/BuildButton.h"
#include "buttons/MoveButton.h"
#include "buttons/BuildBarrackButton.h"
#include "buttons/BuildDrillButton.h"
#include "buttons/BuildExtractorButton.h"
#include "buttons/BuildDefenseTurretButton.h"
#include "buttons/BuildBridgeButton.h"
#include "../util/const.h"
#include "../util/ResourceManager.h"
#include "../stores/BuildingStore.h"
#include "../stores/UnitStore.h"


class UIManager {
private:
    std::map<Action, UIComponent *> components;
public:
    UIManager();

    /// Draw UI
    /// \param resourceManager
    void draw(const ResourceManager &resourceManager) const;

    /// Handle click on an action button
    /// \param position
    /// \param action
    void clickActionButton(const Vect2D position, Action &action);

    /// Activate right buttons depending on entity clicked
    /// \param type of clicked entity
    void displayButton(EntityType type);

    void clearUi();

};
