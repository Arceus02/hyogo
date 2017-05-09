#include "ResourceManager.h"

void ResourceManager::loadResource(AssetId assetId, const std::string &assetPath) {
	assets.emplace(assetId, assetPath);
}

void ResourceManager::initResources() {
	loadResource(TERRAIN_MEADOW, srcPath("assets/terrain/meadow.png"));
	loadResource(TERRAIN_FOREST, srcPath("assets/terrain/forest.png"));
	loadResource(TERRAIN_RIVER, srcPath("assets/terrain/river.png"));
	loadResource(UNIT_SCOUT, srcPath("assets/units/scout.png"));
	loadResource(UNIT_INFANTRY_MELEE, srcPath("assets/units/infantry_melee.png"));
	loadResource(UNIT_CAVALRY, srcPath("assets/units/cavalry.png"));
	loadResource(UNIT_HEAVY, srcPath("assets/units/heavy.png"));
	loadResource(UNIT_BALLISTIC, srcPath("assets/units/ballistic.png"));
	// TODO building resources
	loadResource(UI_PANEL_BOTTOM, srcPath("assets/ui/background_bottom_panel.png"));
    loadResource(UI_ATTACK_BUTTON, srcPath("assets/ui/AttackButton.png"));
    loadResource(UI_MOVE_BUTTON, srcPath("assets/ui/MoveButton.png"));
    loadResource(UI_BUILD_BUTTON, srcPath("assets/ui/BuildButton.png"));
}

const Asset &ResourceManager::getResource(AssetId assetId) const {
	return assets.at(assetId);
}
