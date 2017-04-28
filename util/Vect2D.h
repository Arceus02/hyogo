#pragma once

// TODO change to Imagine++ vector
struct Vect2D {
	int x, y;

	Vect2D(int x, int y);

	Vect2D operator+(Vect2D v);

	Vect2D operator-(Vect2D v);

	Vect2D operator*(int a);

	Vect2D operator/(int a);

	void operator+=(Vect2D v);

	void operator-=(Vect2D v);

	void operator*=(int a);

	void operator/=(int a);

	bool inside(Vect2D p1, Vect2D p2);
};