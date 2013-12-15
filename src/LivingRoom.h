#ifndef LIVINGROOM_H
#define LIVINGROOM_H

#include "SDL/SDL.h"
#include "Game.h"
class LivingRoom {
private:
	SDL_Surface* image;
	SDL_Rect exit;
public:
	LivingRoom();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif