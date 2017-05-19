#pragma once

#include <Imagine/Common.h>

using namespace Imagine;


// Bind annoying FVector<things> to simple and elegant Vect2D
typedef FVector<int,2> Vect2D;

/// Test if p1 is in the rectangle formed by p2 and p3
/// \param p1 vector to test
/// \param p2 rectangle point 1
/// \param p3 rectangle point 2
/// \return p1 in (p2,p3) rectangle
bool inside(const Vect2D &p1, const Vect2D &p2, const Vect2D &p3);

Vect2D modulo(const Vect2D &v, int a);