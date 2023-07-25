#include "main.h"

/**
 * displayhuint - Prints a short unsigned integer.
 *
 * @args: Input argument list containing the
 * short unsigned integer to print.
 * @buffer: Buffer pointer where the output will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of characters printed.
 */

int displayhuint(va_list args, char *buffer, unsigned int buf_i)
{
unsigned short int input_int, int_digit, int_tmp, a, dvs;

/* Extract the short unsigned integer from the argument
 * list
 */
input_int = va_arg(args, unsigned int);

/* Initialize temporary variables */
int_tmp = input_int;
dvs = 1;

/* Calculate the divisor */
while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}

/* Print each digit of the short unsigned integer */
for (a = 0; dvs > 0; dvs /= 10, a++)
{
buf_i = hand_buff(buffer, ((input_int / dvs) % 10) + '0', buf_i);
}

return (a);
}
