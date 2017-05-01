#include "Game.h"

Game::Game() : map(MapGen::uniformRandomMapGenerator(50, 50)), viewOffset(Vect2D(0, 0)) {
	this->window = openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hyogo");
	// TODO change map generation
	// TODO REMOVE
	FightingUnit scoutTest(FightingUnits::SCOUT, Vect2D(1, 1));
	this->unitStore.add(scoutTest);
}

void Game::addViewOffset(Vect2D v) {
	this->viewOffset += v;
	if (this->viewOffset.x > 0)
		this->viewOffset.x = 0;
	if (this->viewOffset.y > 0)
		this->viewOffset.y = 0;
	if (this->viewOffset.x + map.getWidth() * MAP_SQUARE_PIXEL_SIZE < WINDOW_WIDTH)
		this->viewOffset.x = -map.getWidth() * MAP_SQUARE_PIXEL_SIZE + WINDOW_WIDTH;
	if (this->viewOffset.y + map.getHeight() * MAP_SQUARE_PIXEL_SIZE < WINDOW_HEIGHT)
		this->viewOffset.y = -map.getHeight() * MAP_SQUARE_PIXEL_SIZE + WINDOW_HEIGHT;
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
						addViewOffset(Vect2D(0, 16));
						break;
					case KEY_DOWN:
						addViewOffset(Vect2D(0, -16));
						break;
					case KEY_LEFT:
						addViewOffset(Vect2D(16, 0));
						break;
					case KEY_RIGHT:
						addViewOffset(Vect2D(-16, 0));
						break;
					default:
						break;
				}
				break;
			case EVT_BUT_ON: {
				// TODO handle mouse
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
	// TODO update game state : entity store, building store
}

void Game::draw() {
	Buffer buffer(WINDOW_WIDTH, WINDOW_HEIGHT);
	// calculate render range
	int minXRender = -viewOffset.x / MAP_SQUARE_PIXEL_SIZE;
	int maxXRender = WINDOW_WIDTH / MAP_SQUARE_PIXEL_SIZE + minXRender + 2;
	int minYRender = -viewOffset.y / MAP_SQUARE_PIXEL_SIZE;
	int maxYRender = WINDOW_HEIGHT / MAP_SQUARE_PIXEL_SIZE + minYRender + 2;
	minXRender = (minXRender < 0) ? 0 : minXRender;
	minYRender = (minYRender < 0) ? 0 : minYRender;
	maxXRender = (maxXRender > map.getWidth()) ? map.getWidth() : maxXRender;
	maxYRender = (maxYRender > map.getHeight()) ? map.getHeight() : maxYRender;
	Vect2D minRender(minXRender, minYRender), maxRender(maxXRender, maxYRender);
	// draw map
	this->map.draw(buffer, viewOffset, minRender, maxRender);
	// draw units
	this->unitStore.draw(buffer, viewOffset, minRender, maxRender);
	// draw buildings
	this->buildingStore.draw(buffer, viewOffset, minRender, maxRender);
	// TODO draw UI
	// draw buffer on screen
	Imagine::noRefreshBegin();
	Imagine::fillRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, Imagine::AWHITE);
	buffer.drawOnScreen();
	Imagine::noRefreshEnd();
}