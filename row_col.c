#include "atlas.h"

/**
  * get_total_col - get nb of total colomns
  * @vars: pointer to global variables
  * Return: total colomns
  */

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

/**
  * get_total_row - get nb of total rows
  * @vars: global variables
  * Returns: total rows
  */

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
