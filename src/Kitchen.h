#ifndef KITCHEN_H
#define KITCHEN_H

#include "SDL/SDL.h"
#include "Game.h"
class Kitchen {
private:
	SDL_Surface* image;
	SDL_Rect exit;
public:
	Kitchen();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif