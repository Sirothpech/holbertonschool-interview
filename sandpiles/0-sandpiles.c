#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 sandpile
 * @grid2: Right 3x3 sandpile
 *
 * Description: This function computes the sum of two sandpiles and stores the
 * result in the left sandpile (grid1). The function assumes that both grid1
 * and grid2 are individually stable sandpiles. A sandpile is considered stable
 * when none of its cells contains more than 3 grains.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Iterate through each cell of the sandpiles */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/* Add the corresponding cells */
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Check and perform topple if needed */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 sandpile
 *
 * Return: 1 if the sandpile is stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	/* Iterate through each cell of the sandpile */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/* Check if the cell contains more than 3 grains */
			if (grid[i][j] > 3)
			{
				return (0); /* Not stable */
			}
		}
	}
	return (1); /* Stable */
}

/**
 * topple - Performs topple operation on the sandpile
 * @grid: 3x3 sandpile
 *
 * Description: This function performs the topple operation on the sandpile.
 * If a cell contains more than 3 grains, it redistributes the grains to its
 * adjacent cells.
 */
void topple(int grid[3][3])
{
	int i, j;
	int toppled_grid[3][3] = {{0}};

	/* Iterate through each cell of the sandpile */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/* Redistribute grains if the cell has more than 3 grains */
			if (grid[i][j] > 3)
			{
				toppled_grid[i][j] -= 4; /* Subtract 4 grains from the current cell */

				/* Redistribute 1 grain to the adjacent top cell */
				if (i - 1 >= 0)
					toppled_grid[i - 1][j] += 1;

				/* Redistribute 1 grain to the adjacent bottom cell */
				if (i + 1 < 3)
					toppled_grid[i + 1][j] += 1;

				/* Redistribute 1 grain to the adjacent left cell */
				if (j - 1 >= 0)
					toppled_grid[i][j - 1] += 1;

				/* Redistribute 1 grain to the adjacent right cell */
				if (j + 1 < 3)
					toppled_grid[i][j + 1] += 1;
			}
		}
	}

	/* Update the original sandpile with the toppled result */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += toppled_grid[i][j];
		}
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
