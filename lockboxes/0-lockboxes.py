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

    # Parcours des boîtes ouvertes
    while True:
        temp_open_boxes = open_boxes.copy()

        for box in temp_open_boxes:
            # Vérifier si l'indice de la boîte est valide
            if 0 <= box < len(boxes):
                # Parcours des clés dans la boîte actuelle
                for key in boxes[box]:
                    # Ouvrir la boîte correspondante
                    # si elle n'est pas déjà ouverte
                    if key not in open_boxes:
                        open_boxes.add(key)

        # Si la liste des boîtes ouvertes n'a pas changé,
        # on a atteint la saturation
        if temp_open_boxes == open_boxes:
            break

    # Vérification finale
    return len(open_boxes) == len(boxes)
