#include "LivingRoomItem.h"
#include "Functions.h"

LivingRoomItem::LivingRoomItem() {
	exit.x = 214; 
	exit.y = 557; 
	exit.w = 130; 
	exit.h = 150; 
	item.x = 728; 
	item.y = 266; 
	item.w = 60; 
	item.h = 150; 
	image = Functions::loadImage("livingroomitem.jpg");
}

SDL_Event LivingRoomItem::handleEvents(SDL_Event event, Game* g) {
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
			else if( ( x > item.x ) && ( x < item.x + item.w ) && ( y > item.y ) && ( y < item.y + item.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("Shinra-Mansion-boss.png");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->gotItem = true;
				g->livingRoom = false;
				g->entrance = true;
            }
        }
    }
	return event;
}

void LivingRoomItem::show(Game* g) {
    //Show the button
    Functions::applySurface( 0, 0, image, g->screen);
}