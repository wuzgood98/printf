#include "main.h"

/**
 * displaylint - Prints a long integer.
 * @args: Input argument list containing
 * the long integer to print.
 * @buffer: Buffer pointer where the
 * output will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of chars printed.
 */

int displaylint(va_list args, char *buffer, unsigned int buf_i)
{
unsigned long int int_digit, int_tmp, a, dvs, is_neg;
long int input_int;

input_int = va_arg(args, long int);
is_neg = 0;

if (input_int < 0)
{
/* Handle negative numbers by converting
 * to two's complement
 */
input_int = input_int * -1;
buf_i = hand_buff(buffer, '-', buf_i);
is_neg = 1;
}

int_tmp = int_digit = a = dvs = 0;
while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}

for (a = 0; dvs > 0; dvs /= 10, a++)
{
/* Print each digit of the long integer */
buf_i = hand_buff(buffer, ((input_int / dvs) % 10) + '0', buf_i);
}

return (a + is_neg);
}
