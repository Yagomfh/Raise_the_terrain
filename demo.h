#ifndef DEMO_H
#define DEMO_H

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance*);
int poll_events();
void draw_stuff(SDL_Instance instance);

#endif
