#include "atlas.h"

int main(int argc, char *argv[])
{
	FILE *file_pointer;
	vars_t vars;
	SDL_Instance instance;

	if (argc != 2)
	{
		printf("Usage: ./terrain [file]\n");
		return (0);
	}

	if (init_instance(&instance) != 0)
		return(1);
	init_vars(&vars, argv);
	init_coords(&vars);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(instance, &vars);
		SDL_RenderPresent(instance.renderer);
	}

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	free_nodes(&vars);
	return (0);
}

