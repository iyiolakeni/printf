#include "main.h"

/**
 * flag_handler - Calculates active flags
 * @format : Strinf to print arguments
 * @i: parameter
 * Return: flag
*/
int flag_handler(const char *format, int i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j, new_i;
	int flag = 0;
	const char flag_char[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_array[] = {1, 2, 4, 8, 16, 0};

	for (new_i = *i + 1; format[new_i] != '\0'; new_i++)
	{
		j = 0;
		while (flag_char[j] != '\0')
		{
			if (format[new_i] == flag_char[j])
			{
				flag |= flag_array[j];
				break;
			}
			j++;
		}
		if (flag_char[j] == 0)
			break;
	}

	*i = new_i - 1;

	return (flag);
}
