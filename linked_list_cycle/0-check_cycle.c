#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: A pointer to the head of the linked list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	/*
	 * Initialize two pointers, one moving one node at a time (slow),
	 * and the other moving two nodes at a time (fast).
	 */
	listint_t *slow = list;
	listint_t *fast = list;

	/*
	 * Traverse the list until fast reaches the end of the list
	 * or encounters a cycle (fast and slow meet).
	 */
	while (fast != NULL && fast->next != NULL)
	{
		/* Move slow one node. */
		slow = slow->next;

		/* Move fast two nodes. */
		fast = fast->next->next;

		/* If slow and fast meet, there is a cycle. */
		if (slow == fast)
			return (1); /* There is a cycle. */
	}

	/* If fast reaches the end of the list, there is no cycle. */
	return (0); /* No cycle. */
}
