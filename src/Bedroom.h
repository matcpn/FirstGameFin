#ifndef BEDROOM_H
#define BEDROOM_H

#include "SDL/SDL.h"
#include "Game.h"
class Bedroom {
private:
	SDL_Surface* image;
	SDL_Rect exit;
public:
	Bedroom();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif