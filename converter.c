#include "main.h"
/**
 * unsigned_int - function that convert a number into unsigned integer
 * @arg: Its the list of arguments the function _printf is recieving
 * Return: Number of charcateres (or numberes) to be printed
 */
int unsigned_int(va_list arg)
{
	unsigned int m, number;
	int i, k, count = 0;

	number = va_arg(arg, unsigned int);
	if (number == 0)
	{
		_putchar(number + '0');
		count++;
	}
	else if (number > UINT_MAX)
	{
		m = number - UINT_MAX - 1;
		_putchar(m + '0');
		count++;
	}
	else if (number <= UINT_MAX)
	{
		m = number;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = number;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = number;
		}
		_putchar(m % 10 + '0'), count++;
	}
	else
	{
		m = (UINT_MAX + 1) - number;
		_putchar(m + '0'), count++;
	}
	return (count);
}
/**
 * binary_conv - Convert a number into binary number
 * @arg: is the list of arguments the function _printf is receiving
 * Return: Number of characteres (numbers) printing
 */
int binary_conv(va_list arg)
{
	int number_size = 0, number = 0, base = 2, flag = 0;

	number = va_arg(arg, unsigned int);
	number_size = binary_oct_hex_conv(number, base, flag);
	return (number_size);

}
/**
 * octal_conv - Convert a number into octal number
 * @arg: is the list of arguments the function _printf is receiving
 * Return: Number of characteres (numbers) printing
 */
int octal_conv(va_list arg)
{
	int number_size = 0, number = 0, base = 8, flag = 0;

	number = va_arg(arg, unsigned int);
	number_size = binary_oct_hex_conv(number, base, flag);
	return (number_size);
}
/**
 * hex_lowcase_convert - Convert a number into hexadecimal
 * lowercase
 * @arg: is the list of arguments the function _printf is receiving
 * Return: Number of characteres (numbers) printing
 */
int hex_lowcase_convert(va_list arg)
{
	int number_size = 0, number = 0, base = 16, flag = 0;

	number = va_arg(arg, unsigned int);
	number_size = binary_oct_hex_conv(number, base, flag);
	return (number_size);
}
/**
 * hex_Upcase_convert - Convert a number into hexadecimal Uppercase number
 * @arg: is the list of arguments the function _printf is receiving
 * Return: Number of characteres (numbers) printing
 */

int hex_Upcase_convert(va_list arg)
{
	int number_size = 0, number = 0, base = 16, flag = 1;

	number = va_arg(arg, unsigned int);
	number_size = binary_oct_hex_conv(number, base, flag);
	return (number_size);
}
