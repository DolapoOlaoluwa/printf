#include "main.h"


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
