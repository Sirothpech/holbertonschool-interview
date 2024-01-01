
# Lockboxes

## Description
This Python script provides a function `canUnlockAll` that determines if all the lockboxes can be opened based on the given rules.

## Usage
```python
from lockboxes import canUnlockAll

# Example 1
boxes1 = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes1))  # Output: True

# Example 2
boxes2 = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes2))  # Output: True

# Example 3
boxes3 = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes3))  # Output: False
```

## Function Signature
```python
def canUnlockAll(boxes):
    """
    Determine if all the lockboxes can be opened.

    Args:
    - boxes (list of lists): A list of lockboxes where each box is represented as a list of keys.

    Returns:
    - bool: True if all lockboxes can be opened, False otherwise.
    """
    # Your implementation here
```

## Rules
- A key with the same number as a box opens that box.
- All keys are positive integers.
- There can be keys that do not have corresponding boxes.
- The first box `boxes[0]` is unlocked.

Feel free to modify the documentation as needed, and add more details if necessary.