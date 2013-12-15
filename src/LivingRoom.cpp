#include "LivingRoom.h"
#include "Functions.h"

LivingRoom::LivingRoom() {
	exit.x = 214; 
	exit.y = 557; 
	exit.w = 130; 
	exit.h = 150; 
	image = Functions::loadImage("livingroom.jpg");
}

SDL_Event LivingRoom::handleEvents(SDL_Event event, Game* g) {
    //The mouse offsets
    int x = 0, y = 0;
	//If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP ) {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT ) { 
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;
        
            //If the mouse is over the button
            if( ( x > exit.x ) && ( x < exit.x + exit.w ) && ( y > exit.y ) && ( y < exit.y + exit.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("Shinra-Mansion-boss.png");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->entrance = true;
				g->livingRoom = false;
            }
        }
    }
	return event;
}

void LivingRoom::show(Game* g) {
    //Show the button
    Functions::applySurface( 0, 0, image, g->screen);
}