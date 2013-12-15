#include "QuitButton.h"
#include "Game.h"
#include "Functions.h"

QuitButton::QuitButton(int x, int y, int w, int h) {
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;
}

SDL_Event QuitButton::handleEvents(SDL_Event event, Game* g) {
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
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) ) {
				g->quit = true;
            }
        }
    }
	return event;
}

void QuitButton::show(Game* g) {
    //Show the button
    Functions::applySurface( box.x, box.y, g->quitButton, g->screen);
}
