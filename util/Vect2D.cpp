#include "Vect2D.h"

///
/// \param p1 Vector checked
/// \param p2 First bound of rectangle
/// \param p3 Second bound of rectangle
/// \return
bool inside(const Vect2D &p1, const Vect2D &p2, const Vect2D &p3) {
    int x1 = (p2.x() < p3.x()) ? p2.x() : p3.x();
    int x2 = (p2.x() > p3.x()) ? p2.x() : p3.x();
    int y1 = (p2.y() < p3.y()) ? p2.y() : p3.y();
    int y2 = (p2.y() > p2.y()) ? p2.y() : p3.y();
    return x1 <= p1.x() && p1.x() < x2 && y1 <= p1.y() && p1.y() < y2;
}

Vect2D modulo(const Vect2D &v, int a) {
    return Vect2D(v.x() % a, v.y() % a);
}
