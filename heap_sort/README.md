# Heap Sort

This project implements the Heap Sort algorithm, which sorts an array of integers in ascending order. The algorithm follows the sift-down approach to build a max heap and repeatedly extracts the maximum element from the heap to place it at the end of the sorted array.

## Functions Provided

### print_array function

The provided `print_array` function prints an array of integers.

```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

## Tasks

### 0. Heap sort

Write a function `heap_sort` that sorts an array of integers in ascending order using the Heap sort algorithm.

#### Prototype:

```c
void heap_sort(int *array, size_t size);
```

#### Requirements:

- Implement the sift-down heap sort algorithm.
- Print the array after each time you swap two elements.

### 1. Time Complexity

In the file `0-O`, provide the big O notations of the time complexity of the Heap sort algorithm:

- In the best case
- In the average case
- In the worst case

## Usage

To test the Heap sort implementation, compile the provided files along with your implementation:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-heap_sort.c print_array.c -o 0-heap
```

Run the executable:

```bash
./0-heap
```

## Example Output

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

19, 48, 99, 86, 13, 52, 96, 73, 71, 7
...
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```