#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree
 *
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */

/* Function to create a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	/* Allocate memory for the new node */
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	/* Check if memory allocation was successful */
	if (new_node == NULL)
		return (NULL);  /* Allocation failed */

	/* Initialize values of the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	/* Return the pointer to the new node */
	return (new_node);
}
