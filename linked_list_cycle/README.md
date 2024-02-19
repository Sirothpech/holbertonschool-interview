

# Linked List Cycle

## Tasks

### 0. Linked list cycle
**Mandatory**

Technical interview preparation:

- You are not allowed to google anything
- Whiteboard first
- This task and all future technical interview prep tasks will include checks for the efficiency of your solution, i.e. is your solution’s runtime fast enough, does your solution require extra memory usage / mallocs, etc.

Write a function in C that checks if a singly linked list has a cycle in it.

**Prototype:**
```c
int check_cycle(listint_t *list);
```

**Return:**
- 0 if there is no cycle
- 1 if there is a cycle

**Requirements:**
- Only these functions are allowed: write, printf, putchar, puts, malloc, free

## Files

### [lists.h](lists.h)
Header file containing the structure definition and function prototypes.

### [0-linked_lists.c](0-linked_lists.c)
C file with functions for printing, adding a node, and freeing a list.

### [0-main.c](0-main.c)
Main C file for testing the `check_cycle` function.

## Example Usage

```c
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head;
    listint_t *current;
    listint_t *temp;
    int i;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    temp = current->next;
    current->next = head;

    if (check_cycle(head) == 0)
        printf("Linked list has no cycle\n");
    else if (check_cycle(head) == 1)
        printf("Linked list has a cycle\n");

    current = head;
    for (i = 0; i < 4; i++)
        current = current->next;
    current->next = temp;

    free_listint(head);

    return (0);
}
```

## Compilation and Output

```bash
$ gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
$ ./cycle
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```
