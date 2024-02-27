## Palindrome Integer

### Task
Write a function that checks whether or not a given unsigned integer is a palindrome.

### Function Signature
```c
int is_palindrome(unsigned long n);
```

### Parameters
- `n`: Unsigned integer to be checked.

### Return
Your function must return `1` if `n` is a palindrome, and `0` otherwise.

### Constraints
- You are not allowed to allocate memory dynamically (malloc, calloc, …)

### Example
```c
#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ");
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}
```

### Compilation and Execution
```bash
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
./palindrome 1            # Output: 1 is a palindrome.
./palindrome 11           # Output: 11 is a palindrome.
./palindrome 112          # Output: 112 is not a palindrome.
./palindrome 121          # Output: 121 is a palindrome.
./palindrome 12345678987654321   # Output: 12345678987654321 is a palindrome.
./palindrome 123456789987654321  # Output: 123456789987654321 is a palindrome.
./palindrome 1234567898654321     # Output: 1234567898654321 is not a palindrome.
```