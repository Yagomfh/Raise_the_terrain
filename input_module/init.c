#include "atlas.h"

void init_vars(vars_t *vars, char **argv)
{
	vars->filename = argv[1];
	vars->head = NULL;
}

list_t *init_node_end(list_t **head, int x, int y, int z, int row, int col)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *last = *head;

	if (new == NULL)
		return (NULL);

	new->x = x;
	new->y = y;
	new->z = z;
	new->row = row;
	new->col = col;
	new->wx = INCL * new->x - INCL * new->y;
	new->wy = (1 - INCL) * new->x - (1 - INCL) * new->y - new->z;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}

void free_nodes(vars_t *vars)
{
	list_t *current = vars->head;
	list_t *next;
	int i = 0;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	vars->head = NULL;
}

void print_nodes(vars_t *vars)
{
	list_t *head = vars->head;
	int i = 1;

	while (head->next)
	{
		printf("NODE %d\n", i);
		printf("row = %3d | col = %3d\nwx = %4d | wy = %4d\n\n", head->row, head->col, head->wx, head->wy);
		head = head->next;
		i++;
	}
}

void init_coords(vars_t *vars)
{
	char *line = NULL, *token, *delim = " \n";
	size_t line_count = 0;
	int max_p = 0, row = 0, col, max_dbp, x, y;
	FILE *tmp_fp, *fp;

	tmp_fp = fopen(vars->filename, "r");
	while (getline(&line, &line_count, tmp_fp) != -1)
		max_p++;
	free(line), line_count = 0, line = NULL;
	fclose(tmp_fp);

	fp = fopen(vars->filename, "r");
	max_dbp = (WINDOW_H - PADDING * 2) / (max_p - 1);
	y = (WINDOW_H - (max_dbp * (max_p - 1))) / 2;
	while(getline(&line, &line_count, fp) != -1)
	{
		x = (WINDOW_W - (max_dbp * (max_p - 1))) / 2;
		col = 0;
		token = strtok(line, delim);
		while (token)
		{
			init_node_end(&(vars->head), x, y, atoi(token), row, col);
			token = strtok(NULL, delim);
			col++, x += max_dbp;
		}
		row++, y+= max_dbp;
	}
	fclose(fp);
	print_nodes(vars);
}
