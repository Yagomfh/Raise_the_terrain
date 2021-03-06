#ifndef ATLAS_H
#define ATLAS_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

#define WINDOW_W 1260
#define WINDOW_H 720
#define PADDING 10
#define INCL 0.7

/**
  * struct SDL_Instance - struct for window and renderer
  * @window: pointer to window
  * @renderer: pointer to renderer
  */

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
  * struct list_s - linked list with all grid points
  * @x: coordinate x
  * @y: coordinate y
  * @z: coordinate z
  * @row: row nb in grid
  * @col: col nb in grid
  * @rx: INCL * x - INCL * y
  * @ry: (1 - INCL) * x + (1 - INCL) * y - z;
  * @wx: x * cos(vars_t->rotation) - y * sin(vars_t->rotation)
  * @wy: x * sin(vars_t->rotation) + y * cos(vars_t->rotation)
  * @next: pointer to next node
  */

typedef struct list_s
{
	int x;
	int y;
	int z;
	int row;
	int col;
	int rx;
	int ry;
	int wx;
	int wy;
	struct list_s *next;
} list_t;

/**
  * struct variables - global variables
  * @filename: pointer to file w/ altitudes
  * @t_cols: nb of total cols in filename
  * @t_rows: nb of total rows in filename
  * @rotation: Angle * M_PI / 180
  * @alt_mod: altitude modifier
  * @mov_lr: left / right movements
  * @mov_ud: up / down movements
  * @head: pointer to head node of list_t
  */

typedef struct variables
{
	char *filename;
	int t_cols;
	int t_rows;
	int rotation;
	float alt_mod;
	int mov_lr;
	int mov_ud;
	list_t *head;
} vars_t;

/* MAIN */
int main(int argc, char *argv[]);

/* INIT_COORDONATES */
void init_vars(vars_t *vars, char **argv);
void init_coords(vars_t *vars);
list_t *init_node_end(list_t **head, int x, int y, int z, int row, int col);
void free_nodes(vars_t *vars);

/* INIT_INSTANCE */
int init_instance(SDL_Instance *instance);

/* EVENTS */
int poll_events();

/* DRAWS */
void draw_stuff(SDL_Instance instance, vars_t *vars);

/* ROW_COL */
int get_total_col(vars_t *vars);
int get_total_row(vars_t *vars);

/* MOVEMENTS */
void move_grid(vars_t *vars);
void center_grid(vars_t *vars);

#endif
