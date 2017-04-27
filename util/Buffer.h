#pragma once

#include<Imagine/Graphics.h>
#include<vector>
#include "../util/const.h"

class Buffer {
private:
	int width, height;
	Imagine::AlphaColor *map;
public:
	Buffer(int width, int height);

	void drawLine(int x1, int y1, int x2, int y2, Imagine::AlphaColor strokeColor);

	int getWidth();

	int getHeight();

	void set(int x, int y, Imagine::AlphaColor val);

	void drawOnScreen();

	~Buffer();
};