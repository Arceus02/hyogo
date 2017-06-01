#include "UnitStore.h"

void UnitStore::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
                     const Vect2D &maxRender) const {
    for (vector<Unit *>::const_iterator k = list.begin();
         k != list.end(); k++) {
        Unit *unit = *k;
        unit->draw(resourceManager, viewOffset);
        if (unit->isFinishedTurn()) {
            unit->drawIsFinishedTurnBox(viewOffset);
        }
    }

}

