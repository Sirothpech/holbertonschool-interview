#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_palindrome - Check if an unsigned integer is a palindrome.
 * @n: The unsigned integer to check.
 *
 * Return: 1 if the integer is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char str[20];

	sprintf(str, "%lu", n);

	int start = 0;
	int end = strlen(str) - 1;

	while (start < end)
	{
		if (str[start] != str[end])
		{
			return (0);
		}

		start++;
		end--;
	}

	return (1);
}
