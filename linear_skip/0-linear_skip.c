#include "search.h"

/**
 * print_value_checked - Print the value checked at a given index
 * @index: The index of the node
 * @n: The value stored in the node
 */
void print_value_checked(size_t index, int n)
{
	printf("Value checked at index [%lu] = [%d]\n", index, n);
}

/**
 * print_value_found - Print the values where the target value was found
 * @start_index: The index where the search started
 * @end_index: The index where the search ended
 */
void print_value_found(size_t start_index, size_t end_index)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
	start_index, end_index);
}

/**
 * traverse_list - Traverse the skip list until a given value is found
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *traverse_list(skiplist_t *list, int value)
{
	skiplist_t *express = list->express;

	while (express && express->n < value)
	{
		list = express;
		express = express->express;
		if (express)
			print_value_checked(express->index, express->n);
	}

	return (list);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (!list)
		return (NULL);

	skiplist_t *found_node = traverse_list(list, value);

	if (!found_node->express)
	{
		print_value_found(found_node->index, found_node->index);
		while (found_node->next && found_node->next->n < value)
		{
			print_value_checked(found_node->index, found_node->n);
			found_node = found_node->next;
		}
		print_value_checked(found_node->index, found_node->n);
	}
	else
	{
		print_value_found(found_node->index, found_node->express->index);
		while (found_node && found_node->n < value)
		{
			print_value_checked(found_node->index, found_node->n);
			found_node = found_node->next;
		}
		print_value_checked(found_node->index, found_node->n);
	}

	if (found_node && found_node->n == value)
		return (found_node);

	return (NULL);
}
