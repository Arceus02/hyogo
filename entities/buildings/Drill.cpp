#include "Drill.h"

Drill::Drill() : Building(BUILDING_DRILL, "Drill", 20, 3) {}

int Drill::getProduction() {
	switch (level) {
		case 2:
			return 700;
		case 3:
			return 1000;
		default:
            return 350;
	}
}