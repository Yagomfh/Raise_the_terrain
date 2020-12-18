#include "atlas.h"

/**
  * getNCol - gets y equivalent in col + 1
  * @vars: global vars
  * @head: pointer to head node
  * Return: pointer next col node or NULL if not found
  */

list_t *getNCol(vars_t *vars, list_t *head)
{
	int n_col = vars->t_cols;
	int i = 0;

	while (i < n_col)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		i++;
	}
	return (head);
}

/**
  * draw_stuff - draws a 3D grid
  * @instance: pointer to instance
  * @vars: global vars
  * Return: void
  */

void draw_stuff(SDL_Instance instance, vars_t *vars)
{
	list_t *h = vars->head;
	list_t *nCol;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	while (h->next)
	{
		if (h->row == h->next->row)
			SDL_RenderDrawLine(instance.renderer, h->wx, h->wy, h->next->wx, h->next->wy);
		nCol = getNCol(vars, h);
		if (nCol != NULL)
			SDL_RenderDrawLine(instance.renderer, h->wx, h->wy, nCol->wx, nCol->wy);
		h = h->next;
	}
}
