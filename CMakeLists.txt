cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
find_package(Imagine REQUIRED)

project(Hyogo)
set(SOURCE_FILES main.cpp)
add_executable(Hyogo main.cpp Game.h Game.cpp
		entities/Entity.h entities/Entity.cpp
		entities/buildings/Building.h entities/buildings/Building.cpp
		entities/buildings/Barrack.h entities/buildings/Barrack.cpp entities/buildings/Bridge.h entities/buildings/Bridge.cpp
		entities/buildings/CommandCenter.h entities/buildings/CommandCenter.cpp entities/buildings/DefenseTurret.h entities/buildings/DefenseTurret.cpp
		entities/buildings/Drill.h entities/buildings/Drill.cpp entities/buildings/Extractor.h entities/buildings/Extractor.cpp
		entities/units/Unit.h entities/units/Unit.cpp
		entities/units/buildingUnits/Worker.h entities/units/buildingUnits/Worker.cpp
		entities/units/fightingUnits/FightingUnit.h entities/units/fightingUnits/FightingUnit.cpp
		map/Map.h map/Map.cpp map/Field.h map/Field.cpp map/MapGen.h map/MapGen.cpp
		stores/Store.h
		stores/BuildingStore.h stores/BuildingStore.cpp stores/UnitStore.h stores/UnitStore.cpp
		ui/UIManager.h ui/UIManager.cpp ui/UIComponent.h ui/UIComponent.cpp
		util/const.h util/Asset.h util/Asset.cpp util/Vect2D.h util/Vect2D.cpp util/ResourceManager.cpp util/ResourceManager.h)
ImagineUseModules(Hyogo Graphics)
