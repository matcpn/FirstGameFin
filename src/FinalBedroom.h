#ifndef FINALBEDROOM_H
#define FINALBEDROOM_H

#include "SDL/SDL.h"
#include "Game.h"
class FinalBedroom {
private:
	SDL_Surface* image;
	SDL_Rect exit;
public:
	FinalBedroom();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif