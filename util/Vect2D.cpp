#include "Vect2D.h"

Vect2D::Vect2D(int x, int y) : x(x), y(y) {}

Vect2D Vect2D::operator+(const Vect2D &v) const {
	return Vect2D(x + v.x, y + v.y);
}

Vect2D Vect2D::operator-(const Vect2D &v) const {
	return Vect2D(x - v.x, y - v.y);
}

Vect2D Vect2D::operator*(int a) const {
	return Vect2D(x * a, y * a);
}

Vect2D Vect2D::operator/(int a) const {
	return Vect2D(x / a, y / a);
}

void Vect2D::operator-=(const Vect2D &v) {
	x -= v.x;
	y -= v.y;
}

void Vect2D::operator+=(const Vect2D &v) {
	x += v.x;
	y += v.y;
}

void Vect2D::operator*=(int a) {
	x *= a;
	y *= a;
}

void Vect2D::operator/=(int a) {
	x /= a;
	y /= a;
}

bool Vect2D::inside(const Vect2D &p1, const Vect2D &p2) const {
	int x1 = (p1.x < p2.x) ? p1.x : p2.x;
	int x2 = (p1.x > p2.x) ? p1.x : p2.x;
	int y1 = (p1.y < p2.y) ? p1.y : p2.y;
	int y2 = (p1.y > p2.y) ? p1.y : p2.y;
	return x1 <= x && x < x2 && y1 <= y && y < y2;
}
