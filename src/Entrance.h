#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "SDL/SDL.h"
#include "Game.h"
class Entrance {
private:
	SDL_Surface* image;
	SDL_Rect bedroomDoor;
	SDL_Rect exit;
	SDL_Rect kitchenDoor;
	SDL_Rect livingRoomDoor;
public:
	Entrance();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif