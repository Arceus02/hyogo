cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
find_package(Imagine REQUIRED)

project(Hyogo)
set(SOURCE_FILES main.cpp)
add_executable(Hyogo main.cpp Game.cpp Game.h stores/UnitStore.cpp stores/UnitStore.h units/Unit.cpp units/Unit.h stores/Store.cpp stores/Store.cpp stores/Store.h building/Building.cpp building/Building.h stores/BuildingStore.cpp stores/BuildingStore.h map/Map.cpp map/Map.h map/Field.cpp map/Field.h util/const.h util/Buffer.cpp util/Buffer.h map/MapGen.cpp map/MapGen.h)
ImagineUseModules(Hyogo Graphics)