#include "main.h"

/**
 * print_string - prints a string to stdout.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: 1 on success.
 */
int print_string(va_list args, char *buffer, unsigned int buf_i)
{
	char *str, none[] = "(null)";
	unsigned int index;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (index = 0; none[index]; index++)
			buf_i = hand_buff(buffer, none[index], buf_i);
		return (6);
	}
	for (index = 0; str[index]; index++)
		buf_i = hand_buff(buffer, str[index], buf_i);
	return (index);
}
