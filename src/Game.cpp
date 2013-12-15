#include "Game.h"

Game::Game() {
	background = NULL;
	screen = NULL;
	quitButton = NULL;
	quit = false;
	outside = true;
	entrance = false;
	bedroom = false;
	kitchen = false;
	livingRoom = false;
	gotItem = false;
	gotRobot = false;
}