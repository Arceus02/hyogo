#include "Drill.h"

Drill::Drill() : Building(BUILDING_DRILL, "Drill", 20, 3,1,1) {}

int Drill::getProduction() const{
	switch (level) {
		case 2:
            return 600;
		case 3:
			return 1000;
		default:
            return 300;
	}
}
