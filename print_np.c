#include "main.h"

/**
 * print_S - prints the string with non-printable characters.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_S(va_list args, char *buffer, unsigned int buf_i)
{
	char *bin, *hex;
	unsigned int index, cnt, num;
	unsigned char *anon;

	anon = va_arg(args, unsigned char *);
	hex = malloc((8 + 1) * sizeof(char));
	bin = malloc((32 + 1) * sizeof(char));
	for (cnt = index = 0; anon[index]; index++)
	{
		if (anon[index] >= 32 && anon[index] < 127)
		{
			buf_i = hand_buff(buffer, anon[index], buf_i);
		}
		else
		{
			buf_i = hand_buff(buffer, '\\', buf_i);
			buf_i = hand_buff(buffer, 'x', buf_i);
			num = anon[index];
			bin = init_bin(bin, num, 0, 32);
			hex = init_hex(hex, bin, 8, 1);
			buf_i = hand_buff(buffer, hex[6], buf_i);
			buf_i = hand_buff(buffer, hex[7], buf_i);
			cnt += 3;
		}
	}
	free(hex);
	free(bin);
	return (index + cnt);
}
