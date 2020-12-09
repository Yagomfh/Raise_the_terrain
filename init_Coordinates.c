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
	new->wx = (INCL * x - INCL * y) + (WINDOW_W / 2);
	new->wy = ((1 - INCL) * x + (1 - INCL) * y - z) + (WINDOW_H / 4);
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
	int row = 0, col, max_dbp, x, y;
	int max_r = 0, max_c = 0, max_p; 
	FILE *tmp_fp, *fp;

	max_r = get_total_row(vars);
	max_c = get_total_col(vars);
	printf("max_c = %d max_r = %d\n", max_c, max_r);
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
	printf("total: cols = %d, rows = %d\n", col, row);
	vars->t_cols = col, vars->t_rows = row;
	free(line);
	fclose(fp);
	/*print_nodes(vars);*/
}
