#include "Outside.h"
#include "Functions.h"

Outside::Outside() {
	door.x = 511; 
	door.y = 590; 
	door.w = 48; 
	door.h = 65; 
	image = Functions::loadImage("scary mansion.png");
}

SDL_Event Outside::handleEvents(SDL_Event event, Game* g) {
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
            if( ( x > door.x ) && ( x < door.x + door.w ) && ( y > door.y ) && ( y < door.y + door.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("Shinra-Mansion-boss.png");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->outside = false;
				g->entrance = true;
            }
        }
    }
	return event;
}

void Outside::show(Game* g) {
    //Show the button
    Functions::applySurface( 0, 0, image, g->screen);
}