#include "demo.h"

int poll_events()
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
				/* If ESC is pressed */
				if (key.keysym.scancode == 0x29)
					return (1);
				break;
		}
	}
	return (0);
}

void draw_stuff(SDL_Instance instance)
{
	int x, y;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (y = 10; y <= 710; y += 100)
	{
		for (x = 280; x <= 980; x += 100)
		{
			if (x != 980)
				SDL_RenderDrawLine(instance.renderer, x, y, x + 100, y);
			if (y != 710)
				SDL_RenderDrawLine(instance.renderer, x, y, x, y + 100);
		}
	}
}
