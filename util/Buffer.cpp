#include "Buffer.h"

Buffer::Buffer(int width, int height) : width(width), height(height), map(new Imagine::AlphaColor[width * height]) {
	Imagine::AlphaColor transparent(0, 0, 0, 0);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
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
	// alpha blending
	if (val.a() < 255) {
		Imagine::AlphaColor c = this->map[x + y * width];
		int r1 = val[0], g1 = val[1], b1 = val[2];
		int r2 = c[0], g2 = c[1], b2 = c[2];
		float alpha1 = val[3], alpha2 = c[3];
		float alpha = alpha1 + alpha2 * (255 - alpha1);
		int r = (int) ((r1 * alpha1 + r2 * alpha2 * (1 - alpha1)) / alpha);
		int g = (int) ((g1 * alpha1 + g2 * alpha2 * (1 - alpha1)) / alpha);
		int b = (int) ((b1 * alpha1 + b2 * alpha2 * (1 - alpha1)) / alpha);
		byte bR = (byte) r, bG = (byte) g, bB = (byte) b;
		byte bAlpha = (byte) alpha;
		Imagine::AlphaColor nval(bR, bG, bB, bAlpha);
		this->map[x + y * width] = nval;
	} else {
		this->map[x + y * width] = val;
	}
}

void Buffer::drawOnScreen() {
	Imagine::putAlphaColorImage(0, 0, map, WINDOW_WIDTH, WINDOW_HEIGHT);
}

Buffer::~Buffer() {
	delete[] map;
}