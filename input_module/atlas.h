#ifndef ATLAS_H
#define ATLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

#define WINDOW_W 1260
#define WINDOW_H 720
#define PADING 50

typedef struct list_s
{
	int x;
	int y;
	int z;
	int row;
	int col;
	struct list_s *next;
} list_t;

typedef struct variables
{
	list_t *head;
} vars_t;

/* MAIN */
int main(int argc, char *argv[]);

/* INIT */
void init_vars(vars_t *vars);
void init_coords(vars_t *vars, FILE *fp);

#endif
