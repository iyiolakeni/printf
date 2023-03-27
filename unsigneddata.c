#include "main.h"

/**
 * _unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer_array: An array buffer to print unsigned number
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _unsigned(va_list types, char buffer_array[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _unsigned_converter(num, size);

	if (num == 0)
		buffer_array[i--] = '0';

	buffer_array[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_array[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer_array, flags, width, precision, size));
}

/**
 * _octal - Prints an unsigned number in octal notation
 * @types: List  of arguments
 * @buffer_array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _octal(va_list types, char buffer_array[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _unsigned_converter(num, size);

	if (num == 0)
		buffer_array[i--] = '0';

	buffer_array[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_array[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & _HASH && init_num != 0)
		buffer_array[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer_array, flags, wodth, precision, size));
}

/**
 * _hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _hexadecimal(va_list types, char buffer_array[],
	int flags, int width, int precision, int size)
{
	return (_hexa_printer(types, "0123456789abcdef", buffer_array,
		flags, 'x', width, precision, size));
}

/**
 * _unsigned_hexa - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer_array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _unsigned_hexa(va_list types, char buffer_array[],
	int flags, int width, int precision, int size)
{
	return (_hexa_printer(types, "0123456789ABCDEF", buffer_array,
		flags, 'X', width, precision, size));
}

/**
 * _hexa_printer - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer_array: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int _hexa_printer(va_list types, char map_to[], char buffer_array[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _unsigned_converter(num, size);

	if (num == 0)
		buffer_array[i--] = '0';

	buffer_array[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer_array[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & _HASH && init_num != 0)
	{
		buffer_array[i--] = flag_ch;
		buffer_array[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer_array, flags, width, precision, size));
}
