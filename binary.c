#include "main.h"
/**
 * binary_oct_hex_conv - convert a number into binary, octal or hexadecimal
 * @num: Its the number given to convert
 * @base: is the base which the number will be divided with 2,8,16.
 * @flag: flag
 *Return: The number of characteres printed
 */
int binary_oct_hex_conv(unsigned int num, int base, int flag)
{
	char hexUpcase[] = "0123456789ABCDEF";
	char hexLowcase[] = "0123456789abcdef";
	char array[2021];
	char *ptr;
	int i = 2020, j = 0;

	ptr = &array[2020];
	*ptr = '\0';

	do {
		if (flag != 0)
			*--ptr = hexUpcase[num % base];
		else
			*--ptr = hexLowcase[num % base];
		num = num / base;
		i--;
	} while (num != 0);

	for (j = i; array[j] != 0; j++)
	{
		write(1, &array[j], 1);
	}
	return (2020 - i);
}

