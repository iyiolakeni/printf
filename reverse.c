#include "main.h"
/**
 * reverse - function that reverses a string
 * @arg: is the list of arguments the function _printf receives
 * Return: Number of caracteres printing
 */
int reverse(va_list arg)
{
	char *str;
	int count = 0, i, j = 0;

	str = va_arg(arg, char *);
	for (i = 0; str[i] != 0; i++)
	{
		count++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &str[j], 1);
	}
	return (count);
}
/**
 * stringUppercase - Prints a string, when out of range print \x0A
 * @arg: list of arguments the function _printf is sending
 * Return: Number of characteres printing
 */
int stringUppercase(va_list arg)
{
	char *str1;
	int i, count = 0;

	str1 = va_arg(arg, char *);
	if (strl1 == NULL)
		return (NULL);

	for (i = 0; str1[i] != '\0'; i++)
	{
		if ((str1[i] > 0 && str1[i] < 32) || str1[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar('0');
			_putchar('A');
			count += 4;
		}
		else
		{
			write(1, &str1[i], 1);
			count++;
		}
	}
	return (count);
}
