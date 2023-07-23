#include "main.h"

/**
 * init_hex - prints c.
 * @hex: hexadecimals.
 * @bin: binaries.
 * @size: hex size.
 * @uppercase: integer to determine if the hex is lowercase or uppercase.
 *
 * Return: array of binaries.
 */
char *init_hex(char *hex, char *bin, int size, int uppercase)
{
	int index, j, converter, num;

	hex[size] = '\0';
	if (uppercase == 1)
		converter = 55;
	else
		converter = 87;
	for (index = (size * 4) - 1; index >= 0; index--)
	{
		for (num = 0, j = 1; j <= 8; j *= 2, index--)
			num = ((bin[index] - '0') * j) + num;
		index++;
		if (num <= 9)
			hex[index / 4] = num + 48;
		else
			hex[index / 4] = num + converter;
	}
	return (hex);
}
