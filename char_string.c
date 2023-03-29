#include "main.h"

/**
 * print_string - print a string
 * @arg: the list of arguments the function _printf is receiving
 * Return: the number of characteres of the string
 */
int print_string(va_list arg)
{
	int i;
	char *ptr;

	ptr = (va_arg(arg, char *));
	if (ptr == 0)
		ptr = "(null)";
	for (i = 0; ptr[i] != 0; i++)
		write(1, &ptr[i], 1);
	return (i);
}

/**
 * print_char - print a char, or nothing if it is not
 * @arg: the list of arguments the funcion id receiving
 * Return: 1 if it is a char, 0 otherwise
 */
int print_char(va_list arg)
{
	char c;

	c = (va_arg(arg, int));
	write(1, &c, 1);
	return (1);
}

/**
 * print_percent - print the sing percent
 * @arg: the list of arguments the funcion id receiving
 * Return: 1 as just one of character
 */
int print_percent(__attribute__((unused)) va_list arg)
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}
