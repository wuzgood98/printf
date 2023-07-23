#include "main.h"

/**
 * print_unsigned_int - prints unsigned integer represenation
 * of the arguments
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */
int print_unsigned_int(va_list args, char *buffer, unsigned int buf_i)
{
	unsigned int temp, digit, divisor, index;

	digit = va_arg(args, unsigned int);
	temp = digit;
	divisor = 1;
	while (temp > 9)
	{
		divisor *= 10;
		temp /= 10;
	}

	for (index = 0; divisor > 0; divisor /= 10, index++)
	{
		buf_i = hand_buff(buffer, ((digit / divisor) % 10) + '0', buf_i);
	}

	return (index);
}
