#include "atlas.h"

/**
  * move_grid - moves grid according to events
  * @vars: global variables
  * Return: void
  */

void move_grid(vars_t *vars)
{
	list_t *node = vars->head;
	float a = vars->rotation * M_PI / 180;

	while (node)
	{
		node->rx = node->x * cos(a) - node->y * sin(a);
		node->ry = node->x * sin(a) + node->y * cos(a);
		node->wx = INCL * node->rx - INCL * node->ry;
		node->wy = (1 - INCL) * node->rx + (1 - INCL) * node->ry - (node->z / vars->alt_mod);
		node = node->next;
	}
	center_grid(vars);
}

/**
  * center_grid - places 3D draw in the center of the screen
  * @vars: global variables
  * Return: void
  */

void center_grid(vars_t *vars)
{
	list_t *head = vars->head;
	int min_x = 0, min_y = 0;

	while (head)
	{
		head->wx += -(min_x) + WINDOW_W / 2;
		head->wy += -(min_y) + WINDOW_H / 2;
		head = head->next;
	}
}
