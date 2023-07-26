#include "main.h"

/**
 * print_base2 - To converts a number from base 10 to base 2.
 * @args: To list of arguments passed to this function.
 * Return: Length of the number printed
 */
int print_base2(va_list args)
{
	unsigned int decimal_num;
	int k, binary_len;
	char *inverted_binary;
	char *binary;

	decimal_num = va_arg(args, unsigned int);
	if (decimal_num == 0)
		return (_putchar('0'));
	if (decimal_num < 1)
		return (-1);
	binary_len = base_lens(decimal_num, 2);
	inverted_binary = malloc(sizeof(char) * binary_len + 1);
	if (inverted_binary == NULL)
		return (-1);
	for (k = 0; decimal_num > 0; k++)
	{
		if (decimal_num % 2 == 0)
			inverted_binary[k] = '0';
		else
			inverted_binary[k] = '1';

		decimal_num /= 2;
	}
	inverted_binary[k] = '\0';
	binary = rev_strings(inverted_binary);
	if (binary == NULL)
		return (-1);
	put_base(binary);
	free(inverted_binary);
	free(binary);
	return (binary_len);
}


/**
 * print_base8 - To print the numeric representation of a number in base 8.
 * @args: To list of all the arguments passed to the program.
 * Return: Number of symbols printed.
 */

int print_base8(va_list args)
{
	unsigned int decimal_num;
	int octa_len, k;
	char *inverted_octal;
	char *octa_num;

	decimal_num = va_arg(args, unsigned int);
	if (decimal_num == 0)
		return (_putchar('0'));
	if (decimal_num < 1)
		return (-1);
	octa_len = base_lens(decimal_num, 8);
	inverted_octal = malloc(sizeof(char) * octa_len + 1);
	if (inverted_octal == NULL)
		return (-1);
	for (k = 0; decimal_num > 0; k++)
	{
		inverted_octal[k] = (decimal_num % 8) + 48;
		decimal_num /= 8;
	}
	inverted_octal[k] = '\0';
	octa_num = rev_strings(inverted_octal);
	if (octa_num == NULL)
		return (-1);
	put_base(octa_num);
	free(inverted_octal);
	free(octa_num);
	return (octa_len);

}

/**
 * print_base16_lower - To print a representation of a decimal
 *	number on base16 lowercase.
 * @args: List of the arguments passed to the function.
 * Return: Number of characters printed
 */
int print_base16_lower(va_list args)
{
	unsigned int num;
	int hexa_len, i;
	int rem_num;
	char *inverted_hex;
	char *hex;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	hexa_len = base_lens(num, 16);
	inverted_hex = malloc(sizeof(char) * hexa_len + 1);
	if (inverted_hex == NULL)
		return (-1);
	for (i = 0; num > 0; i++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex_case(rem_num, 'x');
			inverted_hex[i] = rem_num;
		}
		else
			inverted_hex[i] = rem_num + 48;
		num /= 16;
	}
	inverted_hex[i] = '\0';
	hex = rev_strings(inverted_hex);
	if (hex == NULL)
		return (-1);
	put_base(hex);
	free(inverted_hex);
	free(hex);
	return (hexa_len);
}



/**
 * print_base16_upper - Prints a representation of a decimal
 *	in upper case base 16.
 * @args: List of the arguments passed to the function.
 * Return: Number of characters printed.
 */
int print_base16_upper(va_list args)
{
	unsigned int num;
	int hexa_len, i;
	int rem_num;
	char *inverted_hex;
	char *hex;

	num = va_arg(args, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	hexa_len = base_lens(num, 16);
	inverted_hex = malloc(sizeof(char) * hexa_len + 1);
	if (inverted_hex == NULL)
		return (-1);
	for (i = 0; num > 0; i++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = check_hex_case(rem_num, 'X');
			inverted_hex[i] = rem_num;
		}
		else
			inverted_hex[i] = rem_num + 48;
		num /= 16;
	}
	inverted_hex[i] = '\0';
	hex = rev_strings(inverted_hex);
	if (hex == NULL)
		return (-1);
	put_base(hex);
	free(inverted_hex);
	free(hex);
	return (hexa_len);
}

/**
 * check_hex_case - check case of hexadecimal
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int check_hex_case(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}

