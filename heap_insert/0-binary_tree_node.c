#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree
 *
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 * Return: Pointer to the new node, or NULL on failure
 */

/* Fonction pour créer un nouveau nœud d'arbre binaire */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    /* Allouer de la mémoire pour le nouveau nœud */
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

    /* Vérifier si l'allocation de mémoire a réussi */
    if (new_node == NULL) {
        return NULL;  // Échec de l'allocation
    }

    /* Initialiser les valeurs du nouveau nœud */
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* Retourner le pointeur vers le nouveau nœud */
    return (new_node);
}