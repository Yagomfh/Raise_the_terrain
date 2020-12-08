#ifndef DEMO_H
#define DEMO_H

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

typedef struct list_s
{
	float x;
	float y;
	float z;
	float wx;
	float wy;
	struct list_s *next;
	struct list_s *right;
	struct list_s *down;
} list_t;

int init_instance(SDL_Instance*);
int poll_events();
void draw_stuff(SDL_Instance instance);
void setCo(FILE *file_p);
#endif
