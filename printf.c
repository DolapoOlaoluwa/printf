#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 *	print a formated string.
 * @format: A string of characters.
 * Return: Length of characters printed.
 */
int _printf(const char *format, ...)
{
	int len_printed_char;
	linker linked_list[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{"i", print_integer},
		{"d", print_integer},
		{"b", print_base2},
		{"u", print_unsigned_int},
		{"o", print_base8},
		{"x", print_base16_lower},
		{"X", print_base16_upper},
		{"r", print_reversed},
		{"R", rot13},
		{"p", print_address},
		{"S", str_nonprintable},
		{"+", print_flag},
		{" ", print_flag},
		{"#", print_flag},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len_printed_char = linking_func(format, linked_list, args);
	va_end(args);
	return (len_printed_char);
}
