#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index where value is located or -1 if not present or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int index;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		if (i != size - 1)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (size == 1 && array[0] != value)
		return (-1);

	index = size / 2;
	if (array[index] == value)
	{
		if (size % 2 == 0)
			index -= 1;
		return (index);
	}
	else if (array[index] > value)
		return (advanced_binary(array, index, value));
	else
	{
		int right = advanced_binary(array + index + 1, size - index - 1, value);

		if (right == -1)
			return (-1);
		return (index + 1 + right);
	}
}
