#!/usr/bin/python3

def canUnlockAll(boxes):
    # Initialisation : Liste des boîtes ouvertes
    open_boxes = [0]

    # Itération jusqu'à saturation
    while True:
        # Copie temporaire de la liste des boîtes ouvertes
        temp_open_boxes = open_boxes.copy()

        # Parcours des boîtes ouvertes
        for box in temp_open_boxes:
            # Parcours des clés dans la boîte actuelle
            for key in boxes[box]:
                # Ouvrir la boîte correspondante si elle n'est pas déjà ouverte
                if key not in open_boxes:
                    open_boxes.append(key)

        # Si la liste des boîtes ouvertes n'a pas changé, on a atteint la saturation
        if temp_open_boxes == open_boxes:
            break

    # Vérification finale
    return len(open_boxes) == len(boxes)