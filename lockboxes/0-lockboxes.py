#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened.

"""

def canUnlockAll(boxes):
    """
    Checks if all the boxes in a given list can be unlocked.
    Args:
        boxes (list): A list of lists representing the boxes and their corresponding keys. Each inner list contains the indices of the boxes that can be unlocked with the key.

    Returns:
        bool: True if all the boxes can be unlocked, False otherwise.
    """

    open_boxes = [0]

    while True:
        temp_open_boxes = open_boxes.copy()

        for box in temp_open_boxes:
            for key in boxes[box]:
                if key not in open_boxes:
                    open_boxes.append(key)

        if temp_open_boxes == open_boxes:
            break

    return len(open_boxes) == len(boxes)