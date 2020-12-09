#include "atlas.h"

list_t *getNCol(vars_t *vars, list_t *head)
{
	int n_col = vars->p_num;
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

void draw_stuff(SDL_Instance instance, vars_t *vars)
{
	int x, y;
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
		SDL_RenderDrawPoint(instance.renderer, h->wx, h->wy);
		h = h->next;
	}
	SDL_RenderDrawPoint(instance.renderer, h->wx, h->wy);
}
