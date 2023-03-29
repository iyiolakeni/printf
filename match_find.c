#include "main.h"
/**
 * spec_func - match format with function format
 * @format: It's a character string
 * @arg: the list of arguments the function _printf is receiving
 * @st_format: array of struct
 * Return: the number of character the function is printing
 */
int spec_func(const char *format, va_list arg, st_fmt st_format[])
{
	int count = 0, i = 0, j, k = 0, num = 0;

	for (i = 0; format && format[i] != 0; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count += 1;
		}
		else
		{
			for (j = 0; st_format[j].fmt; j++)
			{
				if (format[i + 1] == st_format[j].fmt[k])
				{
					num = st_format[j].func(arg);
					count += num;
					i++;
					break;
				}
			}
			if (st_format[j].fmt == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != 0)
				{
					write(1, &format[i], 1);
					write(1, &format[i + 1], 1);
					count += 2;
					i++;
				}
				else
					return (-1);
			}
		}
	}
	if (format == NULL)
		return (-1);
	return (count);

}
