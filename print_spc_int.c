#include "main.h"

/**
 * print_space_int - prints the integer with space of the arguments.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_space_int(va_list args, char *buffer, unsigned int buf_i)
{
	unsigned int digit, d, index, divisor;
	int temp;

	temp = va_arg(args, int);
	if (temp < 0)
	{
		digit = temp * -1;
		buf_i = hand_buff(buffer, '-', buf_i);
	}
	else
	{
		digit = temp;
		buf_i = hand_buff(buffer, ' ', buf_i);
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

	return (index + 1);
}
