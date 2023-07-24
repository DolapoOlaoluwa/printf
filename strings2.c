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
 * print_pointer - To print address
 * @args: Is the argument
 * Return: no of characters to be printed
 */
int print_pointer(va_list args)
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
