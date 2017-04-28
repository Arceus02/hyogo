cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
find_package(Imagine REQUIRED)

project(Hyogo)
set(SOURCE_FILES main.cpp)
add_executable(Hyogo main.cpp Game.cpp Game.h stores/UnitStore.cpp stores/UnitStore.h entities/units/Unit.cpp entities/units/Unit.h
		entities/units/buildingUnits/Worker.cpp entities/units/buildingUnits/Worker.h entities/units/fightingUnits/FightingUnit.cpp entities/units/fightingUnits/FightingUnit.h
		stores/Store.cpp stores/Store.cpp stores/Store.h entities/building/Building.cpp
		entities/building/Building.h stores/BuildingStore.cpp stores/BuildingStore.h map/Map.cpp map/Map.h map/Field.cpp
                map/Field.h util/const.h util/Buffer.cpp util/Buffer.h map/MapGen.cpp map/MapGen.h util/Vect2D.cpp util/Vect2D.h entities/Entity.cpp entities/Entity.h entities/BuyableEntity.cpp entities/BuyableEntity.h
                entities/building/CommandCenter.cpp entities/building/CommandCenter.h entities/building/Barrack.cpp
                entities/building/Barrack.h entities/building/DefenseTurret.cpp entities/building/DefenseTurret.h
                entities/building/Drill.cpp entities/building/Drill.h entities/building/Extractor.cpp
                entities/building/Extractor.h entities/building/Bridge.cpp entities/building/Bridge.h)

ImagineUseModules(Hyogo Graphics)
