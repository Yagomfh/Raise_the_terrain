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
						vars->rotation += 5;
						break;
					case SDLK_RIGHT:
						vars->rotation -= 5;
						break;
					default:
						break;
				}
				break;
		}
	}
	return (0);
}
