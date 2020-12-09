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
	init_vars(&vars);
	file_pointer = fopen(argv[1], "r");
	init_coords(&vars, file_pointer); 
	return (0);
}

