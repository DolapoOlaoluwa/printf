#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * if there is error -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_character - Prints character
 * @args: list of unknown argument
 * Return: The amount of characters printed.
 */
int print_character(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}


/**
 * print_string - Prints a string
 * @args: list of unknown arguments
 * Return: The amount of characters of the string printed
 */
int print_string(va_list args)
{
	int count;
	char *str_ptr;

	str_ptr = va_arg(args, char *);
	if (str_ptr == NULL)
		str_ptr = "(null)";

	count = 0;
	while (str_ptr[count] != '\0')
	{
		_putchar(str_ptr[count]);
		count++;
	}
	return (count);
}


/**
 * print_percent - Prints a percent symbol
 * @args: list of unknown arguments.
 * Return: The amount of characters printed.
 */
int print_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}


/**
 * print_integer - prinnts integer
 * @args: list of unknown arguments.
 * Return: The length of number printed
 */
int print_integer(va_list args)
{
	int number_length, n, div;
	unsigned int num;

	number_length = 0;
	div = 1;
	n = va_arg(args, int);
	if (n < 0)
	{
		number_length += _putchar('-');
		num = n * -1;
	}
	else
		num = n;
	while (num / div > 9)
		div *= 10;
	while (div != 0)
	{
		number_length += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (number_length);
}
