#include "main.h"
#include <math.h>

/**
 * _memcpy - copies memory area
 * @dest: destination for copying
 * @sc: source to copy from
 * @nr: number of bytes to copy
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *sc, unsigned int nr)
{
	unsigned int n;

	for (n = 0; n < nr; n++)
		dest[n] = sc[n];
	dest[n] = '\0';
	return (dest);
}


/**
 * print_address - To print address
 * @args: Is the argument
 * Return: no of characters to be printed
 */
int print_address(va_list args)
{
	int count = 0;
	unsigned int a[16], v, sum;
	unsigned long y, z;
	char *str = "(nil)";

	y = va_arg(args, unsigned long);
	if (y == 0)
	{
		for (v = 0; str[v]; v++)
		{
			_putchar(str[v]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	z = pow(16, 15); /* 16 ^ 15 */
	a[0] = y / z;
	for (v = 1; v < 16; v++)
	{
		z /= 16;
		a[v] = (y / z) % 16;
	}
	for (v = 0, sum = 0; v < 16; v++)
	{
		sum += a[v];
		if (sum || v == 15)
		{
			if (a[v] < 10)
				_putchar('0' + a[v]);
			else
				_putchar('0' + ('a' - ':') + a[v]);
			count++;
		}
	}
	return (count);
}


/**
 * hex_print - To print character in uppercase hex of ascii value
 * @c: character to be printed
 * Return: number of printed characters(always 2)
 */
static int hex_print(char c)
{
	int count;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;

	for (count = 0; count < 2; count++)
	{
		if (d[count] >= 10)
			_putchar('0' + diff + d[count]);
		else
			_putchar('0' + d[count]);
	}
	return (count);
}


/**
 * str_nonprintable - To print string and nonprintable followed by
 * the ASCII code value in hexadecimal
 * @args: Is the arguments
 * Return: number of printed characters
 */
int str_nonprintable(va_list args)
{
	unsigned int h;
	int count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (h = 0; str[h]; h++)
	{
		if (str[h] < 32 || str[h] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += hex_print(str[h]);
		}
		else
		{
			_putchar(str[h]);
			count++;
		}
	}
	return (count);
}


/**
 * print_flag - To print string and nonprintable followed by
 * the ASCII code value in hexadecimal
 * @args: Is the arguments
 * Return: number of printed characters
 */
int print_flag(va_list args)
{
	unsigned int g;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (g = 0; str[g]; g++)
	{
		if (str[g] == 32 || str[g] == 35 || str[g] == 43)
		{
			_putchar(str[g]);
		}
	}
	return (0);
}
