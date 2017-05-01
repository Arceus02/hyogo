#include "extractor.h"

Extractor::Extractor() :
		Building("/assets/buildings/extractor.png", "Extractor", 20) {}

bool Extractor::canLevelUp() {
	return level <= 2;
}

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

