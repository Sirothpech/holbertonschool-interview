#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: double pointer to the head of the list
 * @number: the number to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node;
    listint_t *current;

    new_node = *head;
    current = *head;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
		return (NULL);

    new_node->n = number;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    if (current->n > number)
    {
        *head = new_node;
        new_node->next = current;
        return (new_node);
    }

    while (current->next->n < number)
    {
        current = current->next;

        if (current->next == NULL)
        {
        current->next = new_node;
        new_node->next = NULL;
        return (new_node);
        }
    }
    new_node->next = current->next;
    current->next = new_node;
    return (new_node);
}
