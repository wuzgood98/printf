#include "main.h"

/**
 * displayluint - Prints a long unsigned
 * integer.
 * @args: Input argument list containing
 * the long unsigned integer to print.
 * @buffer: Buffer pointer where the output
 * will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of chars printed.
 */

int displayluint(va_list args, char *buffer, unsigned int buf_i)
{
unsigned long int input_int, int_digit, int_tmp, a, dvs;

input_int = va_arg(args, unsigned long int);

/* Initialize temporary variables */
int_tmp = input_int;
dvs = 1;

/* Calculate the divisor for extracting each digit */
while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}

for (a = 0; dvs > 0; dvs /= 10, a++)
{
/* Print each digit of the long unsigned integer */
buf_i = hand_buff(buffer, ((input_int / dvs) % 10) + '0', buf_i);
}

return (a);
}
