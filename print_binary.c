#include "main.h"

/**
 * print_binary - prints the binary representation of the arguments.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: number of chars printed.
 */
int print_binary(va_list args, char *buffer, unsigned int buf_i)
{
	char *b;
	int digit, cnt, index, is_first, is_neg;

	digit = va_arg(args, int);
	is_neg = 0;
	if (digit == 0)
	{
		buf_i = hand_buff(buffer, '0', buf_i);
		return (1);
	}
	if (digit < 0)
	{
		digit = (digit * -1) - 1;
		is_neg = 1;
	}
	b = malloc((32 + 1) * sizeof(char));
	b = init_bin(b, digit, is_neg, 32);
	is_first = 0;
	for (cnt = index = 0; b[index]; index++)
	{
		if (is_first == 0 && b[index] == '1')
			is_first = 1;
		if (is_first == 1)
		{
			buf_i = hand_buff(buffer, b[index], buf_i);
			cnt++;
		}
	}
	free(b);
	return (cnt);
}
