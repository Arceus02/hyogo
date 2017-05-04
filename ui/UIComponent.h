#pragma once


#include <Imagine/Graphics.h>
#include "../util/Vect2D.h"

class UIComponent {
private:
	Vect2D position;
	int width, height;
	Imagine::AlphaColor borderColor = Imagine::ABLACK, fillColor = Imagine::AWHITE;
public:
	UIComponent(int width, int height);

	virtual void draw() const;

	void setPosition(const Vect2D &position);

	Vect2D getPosition() const;

	void setWidth(int width);

	void setHeight(int height);

	int getWidth();

	int getHeight();

	void setBorderColor(const Imagine::AlphaColor &color);

	void setFillColor(const Imagine::AlphaColor &color);
};




