#pragma once


#include <Imagine/Graphics.h>
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../util/ResourceManager.h"

class UIComponent {
protected:
	Vect2D position;
	int width, height;
    bool activated;
	Imagine::AlphaColor borderColor = Imagine::ABLACK, fillColor = Imagine::AWHITE;
public:
    UIComponent(const int width, const int height, const Vect2D &position);

    virtual void draw(const ResourceManager &resourceManager) const;

    virtual Action getAction() const;

	void setPosition(const Vect2D &position);

	Vect2D getPosition() const;

	void setWidth(int width);

	void setHeight(int height);

	int getWidth();

	int getHeight();

	void setBorderColor(const Imagine::AlphaColor &color);

	void setFillColor(const Imagine::AlphaColor &color);

    bool isActivated ()const;

    void setActivated(bool activate);
};




