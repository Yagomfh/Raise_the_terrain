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

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

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

typedef struct variables
{
	char *filename;
	int t_cols;
	int t_rows;
	int rotation;
	list_t *head;
} vars_t;

/* MAIN */
int main(int argc, char *argv[]);

/* INIT_COORDONATES */
void init_vars(vars_t *vars, char **argv);
void init_coords(vars_t *vars);
list_t *init_node_end(list_t **head, int x, int y, int z, int row, int col);
void free_nodes(vars_t *vars);
void center_grid(vars_t *vars);

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

#endif
