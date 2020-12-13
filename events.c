#include "atlas.h"

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
						puts ("Left key pressed");
						break;
					case SDLK_RIGHT:
						puts("Right key pressed");
					default:
						break;
				}
				break;
		}
	}
	return (0);
}
