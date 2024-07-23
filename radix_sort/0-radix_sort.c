#include "sort.h"

/**
 * get_max - Get the maximum value in the array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Perform a counting sort on the array based on the digit
 * @array: The array
 * @size: Size of the array
 * @exp: The digit's exponent (1, 10, 100, ...)
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array using the radix sort algorithm
 * @array: The array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int max = get_max(array, size);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
