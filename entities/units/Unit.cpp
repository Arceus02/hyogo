#include "Unit.h"

Unit::Unit(AssetId assetId,
           std::string name,
           EntityType type,
           int maxHp,
           int viewRange,
           int speed)
        : Entity(assetId,
                 name,
                 type,
                 maxHp,
                 viewRange),
          speed(speed) {}

void Unit::drawPossibleMoves(Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) const {
    AlphaColor c(0, 0, 255, 50);
    for (std::vector<Vect2D>::const_iterator k = possibleMoves.begin(); k != possibleMoves.end(); k++) {
        Vect2D p = (*k);
        if (inside(p, minRender, maxRender)) {
            Vect2D renderPosition = p * MAP_SQUARE_PIXEL_SIZE + viewOffset;
            Imagine::fillRect(renderPosition.x(), renderPosition.y(), MAP_SQUARE_PIXEL_SIZE, MAP_SQUARE_PIXEL_SIZE, c);
        }
    }
}

void Unit::setCanWalkThroughRiver(bool canWalkThroughRiver) {
    this->canWalkThroughRiver = canWalkThroughRiver;
}

bool Unit::getCanWalkThroughRiver() {
    return canWalkThroughRiver;
}

const int Unit::getSpeed() const {
    return speed;
}

void Unit::setPossibleMoves(std::vector<Vect2D> &possibleMoves) {
    this->possibleMoves = possibleMoves;
}

const bool Unit::isPossibleMove(const Vect2D &position) const {
    for (std::vector<Vect2D>::const_iterator k = possibleMoves.begin(); k != possibleMoves.end(); k++) {
        Vect2D p = (*k);
        if (p.x() == position.x() && p.y() == position.y()) {
            return true;
        }
    }
    return false;
}
