#include "main.h"

/**
 * print_address - prints the address representation of the arguments.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_address(va_list args, char *buffer, unsigned int buf_i)
{
	char *bin, *hex, none[] = "(nil)";
	int is_neg, is_first, cnt, index = 0;
	long int digit;
	void *address;

	address = (va_arg(args, void *));
	if (address == NULL)
	{
		while (none[index])
			buf_i = hand_buff(buffer, none[index], buf_i), index++;
		return (5);
	}
	digit = (intptr_t)address;
	is_neg = 0;
	if (digit < 0)
	{
		digit = (digit * -1) - 1;
		is_neg = 1;
	}
	bin = malloc((64 + 1) * sizeof(char));
	bin = init_bin(bin, digit, is_neg, 64);
	hex = malloc((16 + 1) * sizeof(char));
	hex = init_hex(hex, bin, 16, 0);
	buf_i = hand_buff(buffer, '0', buf_i);
	buf_i = hand_buff(buffer, 'x', buf_i);
	for (is_first = index = cnt = 0; hex[index]; index++)
	{
		if (hex[index] != '0' && is_first == 0)
			is_first = 1;
		if (is_first == 1)
		{
			buf_i = hand_buff(buffer, hex[index], buf_i);
			cnt++;
		}
	}
	free(bin);
	free(hex);
	return (cnt + 2);
}
