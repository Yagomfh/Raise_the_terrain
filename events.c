#include "atlas.h"

/**
  * poll_events - polls events from window
  * @vars: global variables
  * Return: always 0 or 1 of ESC
  */

int poll_events(vars_t *vars)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
				switch (key.keysym.sym)
				{
					case SDLK_ESCAPE:
						return (1);
					case SDLK_LEFT:
						vars->rotation += 5;
						break;
					case SDLK_RIGHT:
						vars->rotation -= 5;
						break;
					case SDLK_UP:
						vars->alt_mod -= 0.1;
						break;
					case SDLK_DOWN:
						vars->alt_mod += 0.1;
					default:
						break;
				}
				break;
		}
	}
	return (0);
}
