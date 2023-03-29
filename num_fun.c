#include "main.h"

/**
 * _isdigit - Prints an integer
 * @arg: the list of arguments the function _printf is receiving
 * Return: count digit
 */
int _isdigit(va_list arg)
{
	unsigned int m;
	int i = 0, k = 0, n = 0, count = 0;

	n = va_arg(arg, int);
	if (n <= INT_MAX && n >= INT_MIN)
	{
		if (n < 0)
		{
			n *= -1;
			_putchar('-');
			count += 1;
		}
		m = n;
		for (k = 0; (m / 10) > 0; k++)
			m /= 10;

		m = n;
		while (k != 0)
		{
			for (i = 0; i < k; i++)
				m /= 10;
			m %= 10;
			_putchar(m + '0');
			count++;
			k--;
			m = n;
		}
		_putchar(m % 10 + '0');
		count++;
	}
	else
	{
		return (-1);
	}
	return (count);
}
