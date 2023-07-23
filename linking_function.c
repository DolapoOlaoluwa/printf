#include "main.h"

/**
 * linking_func - Receives the main string and all the necessary parameters to
 *	print a formated string.
 * @format: A string containing characters.
 * @linked_list: A list of all the posible symbols to
 *	its designed functions.
 * @args: A list containing all the unknow argumentents passed to the program.
 * Return: Length of the characters printed.
 */

int linking_func(const char *format, linker linked_list[], va_list args)
{
	int i, j, retrn_val, len_printed_chars;

	len_printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; linked_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == linked_list[j].sym[0])
				{
					retrn_val = linked_list[j].func_ptr(args);
					if (retrn_val == -1)
						return (-1);
					len_printed_chars += retrn_val;
					break;
				}
			}
			if (linked_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					len_printed_chars += 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			len_printed_chars++;
		}
	}
	return (len_printed_chars);
}
