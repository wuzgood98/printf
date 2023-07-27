#include "main.h"

/**
 * print_pt - prints the character c.
 * @args: list arguments.
 * @b: pointer to the buffer.
 * @b_i: buffer index.
 *
 * Return: 1 on success.
 */
int print_pt(va_list args __attribute__((unused)), char *b, unsigned int b_i)
{
	hand_buff(b, '%', b_i);

	return (1);
}
