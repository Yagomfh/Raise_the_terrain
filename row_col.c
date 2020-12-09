#include "atlas.h"

int get_total_col(vars_t *vars)
{
	FILE *fp;
	char *line = NULL, *token, *delim = " \n";
	size_t line_count = 0;
	int total = 0;

	fp = fopen(vars->filename, "r");
	getline(&line, &line_count, fp);

	token = strtok(line, delim);
	while (token)
	{
		total++;
		token = strtok(NULL, delim);
	}
	free(line);
	fclose(fp);
	return (total);
}

int get_total_row(vars_t *vars)
{
	char *line = NULL;
	size_t line_count = 0;
	FILE *fp;
	int total = 0;

	fp = fopen(vars->filename, "r");
	while (getline(&line, &line_count, fp) != -1)
		total++;
	free(line);
	fclose(fp);
	return (total);
}
