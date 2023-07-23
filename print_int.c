#include "main.h"

/**
 * print_int - prints the integer representation of the arguments.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_int(va_list args, char *buffer, unsigned int buf_i)
{
	unsigned int digit, d, index, divisor, is_neg;
	int temp;

	temp = va_arg(args, int);
	is_neg = 0;
	if (temp < 0)
	{
		digit = temp * -1;
		buf_i = hand_buff(buffer, '-', buf_i);
		is_neg = 1;
	}
	else
	{
		digit = temp;
	}

	d = digit;
	divisor = 1;

	while (d > 9)
	{
		divisor *= 10;
		d /= 10;
	}

	for (index = 0; divisor > 0; divisor /= 10, index++)
	{
		buf_i = hand_buff(buffer, ((digit / divisor) % 10) + '0', buf_i);
	}

	return (index + is_neg);

}
