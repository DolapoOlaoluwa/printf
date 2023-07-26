#include "main.h"

/**
 * print_reversed - To print a fxn to reverse and prints a string
 * @args: argument passed to the fxn
 * Return: Printed Characters
 */

int print_reversed(va_list args)
{
	int lens;
	char *s;
	char *t;

	s = va_arg(args, char *);
	if (s == NULL)
		return (0);

	t = rev_strings(s);
	if (t == NULL)
		return (0);

	for (lens = 0; t[lens] != '\0'; lens++)
		_putchar(t[lens]);

	free(t);
	return (lens);
}

/**
 * rot13 - To convert string to rot13
 * @args: string to convert
 * Return: String converted
 */

int rot13(va_list args)
{
	int f;
	int g;
	char *s;
	char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char w[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(args, char *);
	if (s == NULL)
		return (0);

	for (f = 0; s[f] != '\0'; f++)
	{
		for (g = 0; g <= 52; g++)
		{
			if (s[f] == b[g])
			{
				_putchar(w[g]);
				break;
			}
		}
		if (g == 53)
			_putchar(s[f]);
	}
	return (f);
}


/**
 * rev_strings - reverses a string
 * @t: string to reverse
 * Return: a pointer to a character
 */

char *rev_strings(char *t)
{
	int lens;
	int up;
	char bot;
	char *dest;

	for (lens = 0; t[lens] != '\0'; lens++)
	{}

	dest = malloc(sizeof(char) * lens + 1);
	if (dest == NULL)
		return (0);

	_memcpy(dest, t, lens);
	for (up = 0; up < lens; up++, lens--)
	{
		bot = dest[lens - 1];
		dest[lens - 1] = dest[up];
		dest[up] = bot;
	}
	return (dest);
}

/**
 * put_base - sends character on standard output
 * @str: string to parse
 */
void put_base(char *str)
{
	int n;

	for (n = 0; str[n] != '\0'; n++)
		_putchar(str[n]);
}
/**
 * base_lens - To calculate the octal number length
 * @num: number of length being calculated
 * @base: base to be calculated
 * Return: integer length of a number
 */
unsigned int base_lens(unsigned int num, int base)
{
	unsigned int n;

	for (n = 0; num > 0; n++)
	{
		num = num / base;
	}
	return (n);
}
