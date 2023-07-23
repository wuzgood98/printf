#include "main.h"

/**
 * init_oct - prints c.
 * @octal: octals.
 * @binary: binaries.
 *
 * Return: array of binaries.
 */
char *init_oct(char *octal, char *binary)
{
	int index, j, oct_i, size, num;

	octal[11] = '\0';
	for (index = 31, oct_i = 10; index >= 0; index--, oct_i--)
	{
		if (index > 1)
			size = 4;
		else
			size = 2;
		for (num = 0, j = 1; j <= size; j *= 2, index--)
		{
			num = ((binary[index] - '0') * j) + num;
		}
		index++;
		octal[oct_i] = num + '0';
	}
	return (octal);
}
