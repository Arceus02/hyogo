#pragma once

#include <Imagine/Common.h>

using namespace Imagine;

typedef FVector<int,2> Vect2D;

bool inside(const Vect2D &p1, const Vect2D &p2, const Vect2D &p3); // test if p1 is in the rectangle
                                                                         // formed by p2 and p3
