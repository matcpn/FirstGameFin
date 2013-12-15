#include "Functions.h"
#include "Game.h"

Functions::Functions() {

}
SDL_Surface* Functions::loadImage(std::string fileName) {
	//temp storage to load file
	SDL_Surface* temp = NULL;
	
	//optimized image to use
	SDL_Surface* optimizedImg = NULL;
	
	//load the actual image
	temp = IMG_Load(fileName.c_str());
	
	//make sure the image loaded
	if (temp != NULL) {
		//optimize image
		optimizedImg = SDL_DisplayFormat(temp);
		//free old image
		SDL_FreeSurface(temp);
	}
	
	//return optimized image
	return optimizedImg;
}

void Functions::applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination) {
	//temporary rectangle to hold offsets
	SDL_Rect offset;
	
	//give offsets to rectangle
	offset.x = x;
	offset.y = y;

	//blit the surface
	SDL_BlitSurface(source, NULL, destination, &offset);
}

bool Functions::init(Game* g) {
    //Start SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
		return false;
	}
	//COMMENT OUT ONE OF THE FOLLOWING:
	//Windowed Mode
    g->screen = SDL_SetVideoMode( g->SCREEN_WIDTH, g->SCREEN_HEIGHT, g->SCREEN_BPP, SDL_SWSURFACE );
	//Fullscreen
	//g->screen = SDL_SetVideoMode(g->SCREEN_WIDTH, g->SCREEN_HEIGHT, g->SCREEN_BPP, SDL_FULLSCREEN);
	
	if (g->screen == NULL) {
		return false;
	}
	
	//Set the window caption
	SDL_WM_SetCaption("Haunted Mansion", NULL);
	
	//make sure things worked
	return true;
}

void Functions::cleanUp(Game* g) {
	SDL_FreeSurface(g->screen);
	SDL_FreeSurface(g->background);
	SDL_FreeSurface(g->quitButton);

    //Quit SDL
    SDL_Quit();
}

bool Functions::loadFiles(Game* g) {
	//load image
	g->background = loadImage("scary mansion.png");
	//Load the button sprite sheet
    g->quitButton = loadImage( "quit1.jpg" );
	
	if (g->background == NULL || g->quitButton == NULL) {
		return false;
	}
	
	return true;
}
