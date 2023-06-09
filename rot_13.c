#include "main.h"

/**
 * rot13 - encodes a string using rot13.
 * @arg: the list of arguments the funcion id receiving
 * Return: count characters
 */
int rot13(va_list arg)
{
	int i = 0, j = 0, count = 0;
	char arr1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char arr2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *s;

	s = va_arg(arg, char *);

	for (i = 0; s[i] != 0; i++)
	{
		for (j = 0; arr1[j] != 0; j++)
		{
			if (s[i] == arr1[j])
			{
				count++;
				_putchar(arr2[j]);
				break;
			}
			else if (arr1[j + 1] == 0)
			{
				_putchar(s[i]);
				count++;
			}
		}

	}
	return (count);
}
