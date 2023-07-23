#include "main.h"

/**
 * print_octal - prints the octal representation of the arguments.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_octal(va_list args, char *buffer, unsigned int buf_i)
{
	char *b, *o;
	int digit, index, is_neg, is_first, cnt;

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
	o = malloc((11 + 1) * sizeof(char));
	o = init_oct(o, b);
	for (is_first = index = cnt = 0; o[index]; index++)
	{
		if (o[index] != '0' && is_first == 0)
			is_first = 1;
		if (is_first == 1)
		{
			buf_i = hand_buff(buffer, o[index], buf_i);
			cnt++;
		}
	}
	free(b);
	free(o);
	return (cnt);
}
