#include "atlas.h"

void move_grid(vars_t *vars)
{
	list_t *node = vars->head;
	float a = vars->rotation * M_PI / 180;

	while (node)
	{
		node->rx = node->x * cos(a) - node->y * sin(a);
		node->ry = node->x * sin(a) + node->y * cos(a);
		node->wx = INCL * node->rx - INCL * node->ry;
		node->wy = (1 - INCL) * node->rx + (1 - INCL) * node->ry - node->z;
		node = node->next;
	}
	center_grid(vars);
}
