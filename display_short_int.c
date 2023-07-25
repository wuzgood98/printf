#include "main.h"

/**
 * displayhint - Prints a short integer.
 *
 * @args: Input argument list containing
 * the short integer to print.
 * @buffer: Buffer pointer where the output
 * will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of characters printed.
 */

int displayhint(va_list args, char *buffer, unsigned int buf_i)
{
unsigned short int int_digit, int_tmp, a, dvs, is_neg;
short int input_int;

input_int = va_arg(args, int);
is_neg = 0;
/* Handle negative numbers */
if (input_in < 0)
{
int_digit = input_int * -1;
buf_i = hand_buff(buffer, '-', buf_i);
/* Print the minus sign */
is_neg = 1;
}
else
{
int_digit = input_int;
}
/* Calculate the divisor */
int_tmp = int_digit;
dvs = 1;

while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}

/* Print each digit of the short integer */
for (a = 0; dvs > 0; dvs /= 10, a++)
{
buf_i = hand_buff(buffer, ((int_digit / dvs) % 10) + '0', buf_i);
}

return (a + is_neg);
}
