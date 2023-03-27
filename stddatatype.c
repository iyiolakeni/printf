#include "main.h"

/**
 * _char - Prints a char
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @_size: Size specifier
 * Return: Number of chars printed
 */
int _char(va_list arg, char buffer_array[],
	int flag, int width, int precision, int _size)
{
	char c = va_arg(arg, int);

	return (_char_printer(c, buffer_array, flag, width, precision, _size));
}

/**
 * _string - Prints a string
 * @arg: List a of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _string(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	int i, length = 0;
	char *str = va_arg(arg, char *);

	UNUSED(buffer_array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flag & _MINUS)
		{
			write(1, &str[0], length);
			i = width - length;
			while (i != 0)
				write(1, " ", 1);
			i--;
			return (width);
		}
		else
		{
			i = width - length;
			while (i != 0)
				write(1, " ", 1);
			i--;
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * _percent - Prints a percent sign
 * @arg: Lista of arguments
 * @buffer_array: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _percent(va_list arg, char buffer_array[],
	int flag, int width, int precision, int size)
{
	UNUSED(arg);
	UNUSED(buffer_array);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * _int - Print int
 * @arg: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int _int(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(arg, long int);
	unsigned long int num;

	n = _number_size(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (_number_printer(is_negative, i, buffer, flags,
				width, precision, size));
}

/**
 * _binary - Prints an unsigned number
 * @arg: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int _binary(va_list arg, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(arg, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = j / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (j / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
