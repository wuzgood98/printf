#include "main.h"

/**
 * print_char - print the occurance of a char.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: 1 on success.
 */
int print_char(va_list args, char *buffer, unsigned int buf_i)
{
	char c;

	c = va_arg(args, int);
	hand_buff(buffer, c, buf_i);

	return (1);
}
