#ifndef QUIT_H
#define QUIT_H

#include "SDL/SDL.h"
#include "Game.h"

class QuitButton {
private:
	//button attributes
	SDL_Rect box;
	
public:
	//Initialize this Button
	QuitButton(int, int, int, int);
	
	//handle events and set sprite region
	SDL_Event handleEvents(SDL_Event, Game*);
	
	//show the button
	void show(Game*);
};
#endif