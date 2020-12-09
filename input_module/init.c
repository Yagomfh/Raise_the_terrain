#include "atlas.h"

void init_vars(vars_t *vars)
{
	vars->head = NULL;
}

list_t *add_node_end(list_t **head)
{
	list_t *new = malloc(sizeof(list_t));
	list_t *last = *head;

	if (new == NULL)
		return (NULL);

	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->row = 0;
	new->col = 0;
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
	printf("%d nodes freed\n", i);
	vars->head = NULL;
}

void init_linked_list(int max_p, vars_t *vars)
{

	int total_p = max_p * max_p;
	int i = 0;

	while (i < total_p)
	{
		add_node_end(&(vars->head));
		i++;
	}
	printf("%d nodes added\n ", i);
	puts("Linked List Initialised");
	free_nodes(vars);
	puts("Linked list freed properly");
}

void init_coords(vars_t *vars, FILE *fp)
{
	char *line = NULL;
	size_t line_count = 0;
	int max_p = 0;

	while (getline(&line, &line_count, fp) != -1)
		max_p++;
	free(line);
	init_linked_list(max_p, vars);
}
