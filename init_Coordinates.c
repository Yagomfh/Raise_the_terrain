#include "atlas.h"

void init_vars(vars_t *vars, char **argv)
{
	vars->t_rows = 0;
	vars->t_cols = 0;
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
	new->wx = (INCL * x - INCL * y);
	new->wy = ((1 - INCL) * x + (1 - INCL) * y - z);
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

void center_grid(vars_t *vars)
{
	list_t *head = vars->head;
	int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
	int padx, pady;

	while (head)
	{
		if (head->wx < min_x)
			min_x = head->wx;
		if (head->wy < min_y)
			min_y = head->wy;
		if (head->wx > max_x)
			max_x = head->wx;
		if (head->wy > max_y)
			max_y = head->wy;
		head = head->next;
	}
	padx = (min_x - max_x + WINDOW_W) / 2;
	pady = (min_y - max_y + WINDOW_H) / 2;
	printf("padx = %d || pady = %d\n", padx, pady);
	head = vars->head;
	while (head)
	{
		head->wx += -(min_x) + padx;
		head->wy += -(min_y) + pady;
		head = head->next;
	}
	printf("max_x = %d || max_y = %d\n", max_x, max_y);
	printf("min_x = %d || min_y = %d\n", min_x, min_y);
}

void init_coords(vars_t *vars)
{
	char *line = NULL, *token, *delim = " \n";
	size_t line_count = 0;
	int row = 0, col, max_dbp, x, y;
	int max_r = 0, max_c = 0, max_p; 
	FILE *tmp_fp, *fp;

	max_r = get_total_row(vars);
	max_c = get_total_col(vars);
	vars->t_cols = max_c, vars->t_rows = max_r;
	max_p = max_r;
	if (max_r < max_c)
		max_p = max_c;

	fp = fopen(vars->filename, "r");
	max_dbp = (WINDOW_H - PADDING * 2) / (max_p - 1);
	y = 0;
	while(getline(&line, &line_count, fp) != -1)
	{
		x = 0;
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
	free(line);
	fclose(fp);
}
