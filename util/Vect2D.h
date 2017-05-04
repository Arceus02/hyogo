#pragma once

// TODO change to Imagine++ vector
struct Vect2D {
	int x, y;

	Vect2D(int x, int y);

	Vect2D operator+(const Vect2D &v) const;

	Vect2D operator-(const Vect2D &v) const;

	Vect2D operator*(int a) const;

	Vect2D operator/(int a) const;

	void operator+=(const Vect2D &v);

	void operator-=(const Vect2D &v);

	void operator*=(int a);

	void operator/=(int a);

	bool inside(const Vect2D &p1, const Vect2D &p2) const;
};