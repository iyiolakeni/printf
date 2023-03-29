#include "main.h"
/**
 * _printf - print a char or a string
 * @format: It's a character string
 * Return: the number of character the function is printing
 */
int _printf(const char *format, ...)
{
	st_fmt st_format[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", _isdigit},
		{"i", _isdigit},
		{"%", print_percent},
		{"b", binary_conv},
		{"u", unsigned_int},
		{"o", octal_conv},
		{"x", hex_lowcase_convert},
		{"X", hex_Upcase_convert},
		{"S", stringUppercase},
		{"r", reverse},
		{"R", rot13},
		{NULL, NULL}};

	va_list arg;
	int count = 0;

	va_start(arg, format);
	count =	spec_func(format, arg, st_format);
	va_end(arg);
	return (count);
}
