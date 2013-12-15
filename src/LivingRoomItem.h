#ifndef LIVINGROOMITEM_H
#define LIVINGROOMITEM_H

#include "SDL/SDL.h"
#include "Game.h"
class LivingRoomItem {
private:
	SDL_Surface* image;
	SDL_Rect exit;
	SDL_Rect item;
public:
	LivingRoomItem();
	SDL_Event handleEvents(SDL_Event, Game*);
	void show(Game*);
};
#endif