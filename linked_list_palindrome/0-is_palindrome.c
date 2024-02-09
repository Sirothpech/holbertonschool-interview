#include "lists.h"
#include <stddef.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return 1; // An empty list or a single-node list is a palindrome

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev = NULL;
    listint_t *temp;

    // Find the middle of the list using the slow and fast pointers
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        // Reverse the first half of the list
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // If the number of nodes is odd, move the slow pointer one step forward
    if (fast != NULL)
        slow = slow->next;

    // Compare the reversed first half with the second half
    while (slow != NULL)
    {
        if (slow->n != prev->n)
            return 0; // Not a palindrome

        slow = slow->next;
        prev = prev->next;
    }

    return (1); // It is a palindrome
}
