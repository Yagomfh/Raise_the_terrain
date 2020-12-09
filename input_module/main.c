#include "atlas.h"

int main(int argc, char *argv[])
{
	FILE *file_pointer;
	vars_t vars;

	if (argc != 2)
	{
		printf("Usage: ./terrain [file]\n");
		return (0);
	}
	init_vars(&vars, argv);
	init_coords(&vars); 
	fclose(file_pointer);
	free_nodes(&vars);
	return (0);
}

