#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>


/**
 * struct format - the struct by name stfmt
 * @fmt: index by function
 * @func: pointer to function - funtion print
 */
typedef struct format
{
	char *fmt;
	int (*func)(va_list arg);
} st_fmt;

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list);
int print_char(va_list);
int print_percent(va_list);
int spec_func(const char *, va_list, st_fmt st_format[]);
int _isdigit(va_list);
int binary_conv(va_list);
int octal_conv(va_list);
int hex_Upcase_convert(va_list);
int hex_lowcase_convert(va_list);
int binary_oct_hex_conv(unsigned int, int, int);
int unsigned_int(va_list arg);
int stringUppercase(va_list arg);
int reverse(va_list arg);
int rot13(va_list);
#endif
