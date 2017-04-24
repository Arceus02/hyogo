#include "Buffer.h"

Buffer::Buffer(int width, int height) : width(width), height(height), map(new Imagine::AlphaColor[width * height]) {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			Imagine::AlphaColor transparent(0, 0, 0, 0);
			this->map[x + y * width] = transparent;
		}
	}
}

void Buffer::drawLine(int x1, int y1, int x2, int y2, Imagine::AlphaColor strokeColor) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	for (int x = x1; x <= x2; x++) {
		int y = y1 + dy * (x - x1) / dx;
		this->map[x + y * this->width] = strokeColor;
	}
}

int Buffer::getWidth() {
	return width;
}

int Buffer::getHeight() {
	return height;
}

void Buffer::set(int x, int y, Imagine::AlphaColor val) {
	this->map[x + y * width] = val;
}

void Buffer::drawOnScreen() {
	Imagine::putAlphaColorImage(0, 0, map, WINDOW_WIDTH, WINDOW_HEIGHT);
}

Buffer::~Buffer() {
	delete[] map;
}