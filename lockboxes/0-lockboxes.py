#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.

    Args:
        boxes (list): A list of lists representing the boxes and
        their corresponding keys.
        Each inner list contains the indices of the boxes that can be
        opened with the key.

    Returns:
        bool: True if all the boxes can be opened, False otherwise.
    """
    # Initialisation : Liste des boîtes ouvertes
    open_boxes = {0}
    # Liste des boîtes à ouvrir
    to_open = set(range(1, len(boxes)))

    # Parcours des boîtes ouvertes
    while open_boxes:
        box = open_boxes.pop()
        # Parcours des clés dans la boîte actuelle
        for key in boxes[box]:
            # Ouvrir la boîte correspondante
            # si elle n'est pas déjà ouverte
            if key in to_open:
                open_boxes.add(key)
                to_open.remove(key)

    # Vérification finale
    return len(to_open) == 0
