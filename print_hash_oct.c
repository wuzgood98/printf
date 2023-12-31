#include "main.h"

/**
 * print_hash_oct - prints the octal starting with 0.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_hash_oct(va_list args, char *buffer, unsigned int buf_i)
{
	char *bin, *oct;
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
	buf_i = hand_buff(buffer, '0', buf_i);
	bin = malloc((32 + 1) * sizeof(char));
	bin = init_bin(bin, digit, is_neg, 32);
	oct = malloc((11 + 1) * sizeof(char));
	oct = init_oct(oct, bin);
	for (is_first = index = cnt = 0; oct[index]; index++)
	{
		if (oct[index] != '0' && is_first == 0)
			is_first = 1;
		if (is_first == 1)
		{
			buf_i = hand_buff(buffer, oct[index], buf_i);
			cnt++;
		}
	}
	free(bin);
	free(oct);
	return (cnt + 1);
}
