#include "BuildingStore.h"

void BuildingStore::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
                         const Vect2D &maxRender) const {
    for (std::vector<Building *>::const_iterator k = list.begin(); k != list.end(); k++) {
        if (inside((*k)->getPosition(), minRender, maxRender)) {
            (*k)->draw(resourceManager, viewOffset);
        }
    }
}




