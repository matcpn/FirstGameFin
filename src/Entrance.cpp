#include "Entrance.h"
#include "Functions.h"

Entrance::Entrance() {
	exit.x = 446; 
	exit.y = 601; 
	exit.w = 132; 
	exit.h = 100; 
	bedroomDoor.x = 819;
	bedroomDoor.y = 274;
	bedroomDoor.w = 60;
	bedroomDoor.h = 140;
	kitchenDoor.x = 140;
	kitchenDoor.y = 300;
	kitchenDoor.w = 60;
	kitchenDoor.h = 140;
	livingRoomDoor.x = 457;
	livingRoomDoor.y = 215;
	livingRoomDoor.w = 100;
	livingRoomDoor.h = 100;
	image = Functions::loadImage("Shinra-Mansion-boss.png");
}

SDL_Event Entrance::handleEvents(SDL_Event event, Game* g) {
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
				g->background = Functions::loadImage("scary mansion.png");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->outside = true;
				g->entrance = false;
            }
			else if( ( x > bedroomDoor.x ) && ( x < bedroomDoor.x + bedroomDoor.w ) && ( y > bedroomDoor.y ) && ( y < bedroomDoor.y + bedroomDoor.h ) && g->gotItem ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("bedroom2.jpg");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->bedroom = true;
				g->gotRobot = true;
				g->entrance = false;
            }
			else if( ( x > bedroomDoor.x ) && ( x < bedroomDoor.x + bedroomDoor.w ) && ( y > bedroomDoor.y ) && ( y < bedroomDoor.y + bedroomDoor.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("bedroom.jpg");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->bedroom = true;
				g->entrance = false;
            }
			else if( ( x > kitchenDoor.x ) && ( x < kitchenDoor.x + kitchenDoor.w ) && ( y > kitchenDoor.y ) && ( y < kitchenDoor.y + kitchenDoor.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("kitchen.jpg");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->kitchen = true;
				g->entrance = false;
            }
			else if( ( x > livingRoomDoor.x ) && ( x < livingRoomDoor.x + livingRoomDoor.w ) && ( y > livingRoomDoor.y ) && ( y < livingRoomDoor.y + livingRoomDoor.h ) && g->gotItem ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("livingroom.jpg");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->livingRoom = true;
				g->entrance = false;
            }
			else if( ( x > livingRoomDoor.x ) && ( x < livingRoomDoor.x + livingRoomDoor.w ) && ( y > livingRoomDoor.y ) && ( y < livingRoomDoor.y + livingRoomDoor.h ) ) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("livingroomitem.jpg");
				Functions::applySurface( 0, 0, g->background, g->screen);
				g->livingRoom = true;
				g->entrance = false;
            }
        }
    }
	return event;
}

void Entrance::show(Game* g) {
    //Show the button
    Functions::applySurface( 0, 0, image, g->screen);
}