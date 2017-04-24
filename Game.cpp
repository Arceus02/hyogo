#include "Game.h"

Game::Game() : map(MapGen::uniformRandomMapGenerator(50, 50)) {
	this->window = openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hyogo");
	// TODO change map generation
}

void Game::play() {
	this->playing = true;
	while (this->playing) {
		this->logic();
		// no frame skip
		this->draw();
	}
}

void Game::logic() {
	// TODO get event
	/*
	 * Events :
	 * 	keyboard :
	 * 		up/down/left/right : move camera
	 */
	Event ev;
	do {
		getEvent(1, ev); // ev becomes the next event
		switch (ev.type) {
			case EVT_KEY_ON:
				switch (ev.key) {
					case KEY_UP:
						map.addViewOffset(0, 16);
						break;
					case KEY_DOWN:
						map.addViewOffset(0, -16);
						break;
					case KEY_LEFT:
						map.addViewOffset(16, 0);
						break;
					case KEY_RIGHT:
						map.addViewOffset(-16, 0);
						break;
					default:
						break;
				}
				break;
			case EVT_BUT_ON: {
				int x = ev.pix.x();
				int y = ev.pix.y();
				cout << "Click " << x << " " << y << endl;
				break;
			}
			default:
				break;
		}
	} while (ev.type != EVT_NONE);
	// TODO update UI
	// TODO update game state
}

void Game::draw() {
	Buffer buffer(WINDOW_WIDTH, WINDOW_HEIGHT);
	// draw map
	this->map.draw(buffer);
	// TODO draw UI
	// draw buffer
	Imagine::noRefreshBegin();
	Imagine::fillRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, Imagine::AWHITE);
	buffer.drawOnScreen();
	Imagine::noRefreshEnd();
}