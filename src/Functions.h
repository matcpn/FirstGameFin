#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Game.h"

class Functions {
public:
	Functions();
	static SDL_Surface* loadImage(std::string);
	static void applySurface(int, int, SDL_Surface*, SDL_Surface*);
	static bool init(Game* g);
	static void cleanUp(Game* g);
	static bool loadFiles(Game* g);
};

#endif