#include "drill.h"

Drill::Drill() :
		Building("/assets/buildings/drill.png", "Drill", 20) {}

bool Drill::canLevelUp() {
	return level <= 2;
}

int Drill::getProduction() {
	switch (level) {
		case 1:
			return 350;
		case 2:
			return 700;
		case 3:
			return 1000;
		default:
			break;
	}
}

