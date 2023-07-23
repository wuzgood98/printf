#include "main.h"

/**
 * print_reverse - prints the reversed representation of the string;
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_reverse(va_list args, char *buffer, unsigned int buf_i)
{
	unsigned int index = 0;
	int j = 0;
	char *str, none[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		while (none[index])
		{
			buf_i = hand_buff(buffer, none[index], buf_i);
			index++;
		}
		return (6);
	}
	for (index = 0; str[index]; index++)
		;
	j = index - 1;
	for (; j >= 0; j--)
		buf_i = hand_buff(buffer, str[j], buf_i);
	return (index);
}
