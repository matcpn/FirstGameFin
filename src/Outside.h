#ifndef OUTSIDE_H
#define OUTSIDE_H

#include "SDL/SDL.h"
#include "Game.h"

class Outside {
private:
	SDL_Surface* image;
	SDL_Rect door;
public:
	Outside();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif