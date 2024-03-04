# UTF-8 Validation

Write a method that determines if a given data set represents a valid UTF-8 encoding.

## Prototype

```python
def validUTF8(data)
```

## Return

- True if `data` is a valid UTF-8 encoding, else return False

- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data; therefore, you only need to handle the 8 least significant bits of each integer

## Example

```python
data = [65]
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))  # True

data = [229, 65, 127, 256]
print(validUTF8(data))  # False
```

## Requirements

- The code must be written in Python
- You are not allowed to use any loops or conditional statements (`if`, `else`, `while`, `for`, etc.)
- You can use only arithmetic and bitwise operations
- All tasks will be tested with the same list `data`
- Your code will be checked for correctness with provided test cases

## Tasks

- **0. UTF-8 Validation:**
  Write a method that determines if a given data set represents a valid UTF-8 encoding.

  Example usage:
  ```python
  data = [65]
  print(validUTF8(data))  # True

  data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
  print(validUTF8(data))  # True

  data = [229, 65, 127, 256]
  print(validUTF8(data))  # False
  ```

---
