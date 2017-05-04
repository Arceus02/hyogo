#include "extractor.h"

Extractor::Extractor() :
		Building(BUILDING_EXTRACTOR, "Extractor", 20, 3) {}

int Extractor::getProduction() {
	switch (level) {
		case 1:
			return 5;
		case 2:
			return 10;
		case 3:
			return 50;
		default:
			break;
	}
}

