#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*creation of structure*/

/**
 * struct linker - defines a structure for symbols and functions
 * @sym: the format specifier symbol.
 * @func_ptr: pointer function to @sym associated function.
 */

typedef struct linker
{
	char *sym;
	int (*func_ptr)(va_list);
} linker;


/*needed functions*/


int _printf(const char *format, ...);
int linking_func(const char *format, linker linked_list[], va_list args);
int _putchar(char c);
int print_character(va_list args);
int print_string(va_list args);
int print_percent(__attribute__((unused))va_list args);
int print_integer(va_list args);
int print_reversed(va_list args);
int rot13(va_list args);
char *rev_strings(char *t);
void put_base(char *str);
unsigned int base_lens(unsigned int num, int base);
char *_memcpy(char *dest, char *sc, unsigned int nr);
int print_base2(va_list args);
int print_base8(va_list args);
int print_base16_lower(va_list args);
int print_base16_upper(va_list args);
int check_hex_case(int num, char x);
int print_unsignd(unsigned int n);
int print_unsigned_int(va_list args);
int print_address(va_list args);
int str_nonprintable(va_list args);
int print_flag(va_list args);


#endif /*MAIN_H*/
