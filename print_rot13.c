#include "main.h"

/**
 * print_rot13 - prints the rot13 representation of the string.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index
 *
 * Return: the number of chars printed.
 */
int print_rot13(va_list args, char *buffer, unsigned int buf_i)
{
	char *str, none[] = "(nill)";
	char alphabets[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13_chars[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	unsigned int index, cnt = 0, j;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		while (str[cnt])
		{
			buf_i = hand_buff(buffer, none[cnt], buf_i);
			cnt++;
		}
		return (6);
	}
	while (str[cnt])
	{
		for (index = j = 0; alphabets[j]; j++)
		{
			if (str[cnt] == alphabets[j])
			{
				index = 1;
				buf_i = hand_buff(buffer, rot13_chars[j], buf_i);
				break;
			}
		}
		if (index == 0)
			buf_i = hand_buff(buffer, str[cnt], buf_i);
		cnt++;
	}
	return (cnt);
}
