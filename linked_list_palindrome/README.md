**README: Linked List Palindrome**

### Task Description:
Write a function in C that checks if a singly linked list is a palindrome.

### Function Prototype:
```c
int is_palindrome(listint_t **head);
```

### Return:
- 0 if it is not a palindrome
- 1 if it is a palindrome

### Considerations:
- An empty list is considered a palindrome.

### Provided Files:
- **lists.h:**
  ```c
  #ifndef LISTS_H
  #define LISTS_H

  typedef struct listint_s
  {
      int n;
      struct listint_s *next;
  } listint_t;

  size_t print_listint(const listint_t *h);
  listint_t *add_nodeint_end(listint_t **head, const int n);
  void free_listint(listint_t *head);

  int is_palindrome(listint_t **head);

  #endif /* LISTS_H */
  ```

- **linked_lists.c:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include "lists.h"

  size_t print_listint(const listint_t *h)
  {
      // Implementation of print_listint function
  }

  listint_t *add_nodeint_end(listint_t **head, const int n)
  {
      // Implementation of add_nodeint_end function
  }

  void free_listint(listint_t *head)
  {
      // Implementation of free_listint function
  }
  ```

- **0-main.c:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include "lists.h"

  int main(void)
  {
      // Main function to test the is_palindrome function
  }
  ```

### Testing the Provided Example:
```bash
$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
$ ./palindrome
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

### Note:
- The implementation of the `is_palindrome` function should be added to `0-is_palindrome.c`.
- The testing and inclusion of additional test cases can be done in the `main` function of `0-main.c`.