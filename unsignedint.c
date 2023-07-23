#include "main.h"

/**
 * print_unsignd - Prints unsigned integer.
 * @n: unsigned integer
 * Return: len of numbers printed.
 */

int print_unsignd(unsigned int n)
{
	int number_len, div;
	unsigned int num;

	div  = 1;
	number_len = 0;
	num  = n;

	while (num  / div > 9)
		div *= 10;
	while (div != 0)
	{
		number_len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}
	return (number_len);
}

/**
 * print_unsigned_int - Prints unsigned integer.
 * @args: list of unknown argument.
 * Return: len of numberrs printed.
 */
int print_unsigned_int(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsignd(num));
	if (num < 1)
		return (-1);

	return (print_unsignd(num));
}
