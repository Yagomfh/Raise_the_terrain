#include "atlas.h"

void rotate(int angle, vars_t *vars)
{
	list_t *node = vars->head;
	float a = angle * 3.14 / 180; 
	int x_tmp = node->x;

	printf("a = %f\n", a);
	while (node)
	{
		node->x = node->x * cos(a) - node->y * sin(a);
		node->y = node->x * sin(a) + node->y * cos(a);
		node->wx = INCL * node->x - INCL * node->y;
		node->wy = (1 - INCL) * node->x + (1 - INCL) * node->y - node->z;
		node = node->next;
	}
	center_grid(vars);
}
