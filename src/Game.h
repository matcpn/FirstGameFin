#ifndef GAME_H
#define GAME_H

#include "SDL/SDL.h"
class Game {
public:
	Game();
	//Screen size
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
	const static int SCREEN_BPP = 32; //bits per pixel. 32 bit
	
	bool quit;
	bool outside;
	bool entrance;
	bool bedroom;
	bool kitchen;
	bool livingRoom;
	bool gotItem;
	bool gotRobot;
	
	
	//Images to be used
	SDL_Surface* screen;
	SDL_Surface* background;
	SDL_Surface* quitButton;
};
#endif