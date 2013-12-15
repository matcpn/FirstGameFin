// Haunted Mansion.cpp : Defines the entry point for the console application.
//

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Functions.h"
#include "QuitButton.h"
#include "Game.h"
#include "Outside.h"
#include "Entrance.h"
#include "Bedroom.h"
#include "Kitchen.h"
#include "LivingRoom.h"
#include "LivingRoomItem.h"
#include "FinalBedroom.h"


using std::string;

int main( int argc, char* args[] ) {

	Game* g = new Game();
	SDL_Event event;
	
	QuitButton myButton(924, 0, 100, 100);
	
	if (Functions::init(g) == false) {
		return -1;
	}
	Outside o;
	Entrance e;
	Bedroom b;
	Kitchen k;
	LivingRoom l;
	LivingRoomItem li;
	FinalBedroom fb;
	
	if (Functions::loadFiles(g) == false) {
		return -1;
	}
	
	//apply bg to scene
	Functions::applySurface(0, 0, g->background, g->screen);
	
	//Show the button
	myButton.show(g);
	
	while (g->quit == false) {
		//If there's events to handle
        if( SDL_PollEvent( &event ) ) {
            //Handle button events
            event = myButton.handleEvents(event, g);
			if (g->outside) {
				event = o.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->entrance) {
				event = e.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->bedroom && g->gotItem) {
				event = fb.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->bedroom) {
				event = b.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->kitchen && g->gotRobot) {
				SDL_FreeSurface(g->background);
				g->background = Functions::loadImage("endgame.png");
				Functions::applySurface( 0, 0, g->background, g->screen);
				myButton.show(g);
			}
			else if (g->kitchen) {
				event = k.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->livingRoom && g->gotItem) {
				event = l.handleEvents(event, g);
				myButton.show(g);
			}
			else if (g->livingRoom) {
				event = li.handleEvents(event, g);
				myButton.show(g);
			}
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                g->quit = true;
            }
        }
		
		
		//Update screen
		if (SDL_Flip(g->screen) == -1) {
			return 1;
		}
	}
	
	Functions::cleanUp(g);
    
    return 0;    
}