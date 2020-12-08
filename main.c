#include "demo.h"

int main(int argc, char *argv[])
{
	FILE *file_pointer;
	char *line = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		printf("Usage: ./terrain [file]\n");
		return (0);
	}
	file_pointer = fopen(argv[1], "r");
/*	set_coord(file_pointer);*/
	getline(&line, &len, file_pointer);
	printf("%s\n", line);
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);

	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
