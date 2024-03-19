#include "slide_line.h"
#include <stddef.h>

/**
 * merge_adjacent - Merges adjacent elements in the array
 * @line: Array of integers containing size elements
 * @size: Number of elements in @line
 * @direction: Direction to merge the elements
 *
 * Return: void
 */
void merge_adjacent(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; ++i)
		{
			if (line[i] != 0)
			{
				for (j = i + 1; j < size && line[j] == 0; ++j)
					;
				if (j < size && line[i] == line[j])
				{
					line[i] *= 2;
					line[j] = 0;
					i = j;
				}
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i < size; --i)
		{
			if (line[i] != 0)
			{
				for (j = i - 1; j < size && line[j] == 0; --j)
					;
				if (j < size && line[i] == line[j])
				{
					line[i] *= 2;
					line[j] = 0;
					i = j;
				}
			}
		}
	}
}

/**
 * shift_non_zero_elements - Shifts non-zero elements to the left or right
 * @line: Array of integers containing size elements
 * @size: Number of elements in @line
 * @direction: Direction to slide the elements
 *
 * Return: void
 */
void shift_non_zero_elements(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0, j = 0; i < size; ++i)
		{
			if (line[i] != 0)
			{
				line[j++] = line[i];
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1, j = size - 1; i < size; --i)
		{
			if (line[i] != 0)
			{
				line[j--] = line[i];
			}
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers
 * towards a given direction
 * @line: Array of integers containing size elements
 * @size: Number of elements in @line
 * @direction: Direction to slide the elements
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	merge_adjacent(line, size, direction);
	shift_non_zero_elements(line, size, direction);

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; ++i)
		{
			if (i >= size)
				line[i] = 0;
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size - 1; i < size; --i)
		{
			if (i >= size)
				line[i] = 0;
		}
	}

	return (1);
}
