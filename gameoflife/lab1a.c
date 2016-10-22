/*
 * lab1a.c
 *
 *  Created on: 2016-10-22
 *      Author: Janne Mäkinen
 */

#include <stdio.h>

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */

/* number of generations to evolve the world */
//#define NUM_GENERATIONS 50
#define NUM_GENERATIONS 4

/* functions to implement */

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(void)
{
	int n;

	/* TODO: initialize the world 
	initialize_world();


	for (n = 0; n < NUM_GENERATIONS; n++)
		next_generation();

	/* TODO: output final world state */

	//Original
	initialize_world();
	output_world();

	//First generation
	next_generation();
	output_world();

	//Second generation
	next_generation();
	output_world();

	//Third generation
	next_generation();
	output_world();

	return 0;
}

void next_generation(void) 
{
	   // TODO: for every cell, set the state in the next
	   //generation according to the Game of Life rules
	   //set the state of all the cells in the next generation
	   //   Hint: use get_next_state(x,y) */
	int x, y;
	for (x = 0; x < WORLDWIDTH; x++) 
		{
		for (y = 0; y < WORLDHEIGHT; y++) 
			{
				//world[x][y] = nextstates[x][y];
				//nextstates[x][y] = DEAD;
				int newstate = get_next_state(x, y);
				set_cell_state(x, y, newstate);
			}
		}

	
	//call finalize_evolution() to update the current
	//state of the world to the next generation 
	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y)
{
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules
	   if (get_cell_state(i, j) = DEAD)
	   {
	   set_cell_state(i, j, cell_state);
	   }
	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */
	int next_state = DEAD;

	if (get_cell_state(x, y) == ALIVE)
	{

		// A live cell with fewer than two live neighbors dies
		if (num_neighbors(x, y) < 2)
		{
			next_state = DEAD;
		}

		// A live cell with more than three live neighbors also dies
		if (num_neighbors(x, y) > 3)
		{
			next_state = DEAD;
		}

		// A live cell with exactly two or three live neighbors lives
		if (num_neighbors(x, y) == 2 || (num_neighbors(x, y) == 3))
		{
			next_state = ALIVE;
		}
		if (get_cell_state(x, y) == DEAD)

			// A dead cell with exactly three neighbors becomes alive
			if (num_neighbors(x, y) == 3)
			{
				next_state = ALIVE;
			}
			else
			{
				next_state = DEAD;
			}
	}

	return next_state;
}

int num_neighbors(int x, int y)
{
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE
	   Use get_cell_state(x,y) */
	int count = 0;

	// x = x - 1
	if (get_cell_state(x - 1, y - 1) == ALIVE)
		count++;
	if (get_cell_state(x, y - 1) == ALIVE)
		count++;
	if (get_cell_state(x + 1, y - 1) == ALIVE)
		count++;

	// x = x
	if (get_cell_state(x, y - 1) == ALIVE)
		count++;
	if (get_cell_state(x, y + 1) == ALIVE)
		count++;

	// x = x + 1
	if (get_cell_state(x + 1, y - 1) == ALIVE)
		count++;
	if (get_cell_state(x + 1, y) == ALIVE)
		count++;
	if (get_cell_state(x + 1, y + 1) == ALIVE)
		count++;

	printf("Count 1: %d \n", count);

		return count;

}
