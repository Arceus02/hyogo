#pragma once


#include <map>
#include "Asset.h"

enum AssetId {
	TERRAIN_NONE, TERRAIN_MEADOW, TERRAIN_FOREST, TERRAIN_RIVER,
	UNIT_WORKER,
	UNIT_SCOUT, UNIT_INFANTRY_MELEE, UNIT_INFANTRY_DISTANCE, UNIT_CAVALRY, UNIT_HEAVY, UNIT_BALLISTIC,
	BUILDING_BARRACK, BUILDING_BRIDGE, BUILDING_COMMAND_CENTER, BUILDING_TURRET, BUILDING_DRILL, BUILDING_EXTRACTOR,
	UI_PANEL_BOTTOM
};

class ResourceManager {
private:
	std::map<AssetId, Asset> assets;

	void loadResource(AssetId assetId, const std::string &assetPath);

public:
	void initResources();

	const Asset &getResource(AssetId assetId) const;
};