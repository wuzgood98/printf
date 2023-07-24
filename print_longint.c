#include "main.h"

/**
 * print_longint - prints long integers.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */

int print_longint(va_list args, char *buffer, unsigned int buf_i)
{
unsigned long int int_digit, int_tmp, a, dvs, is_neg;
long int input_int;

/* Get arguments from the va_list */
input_int = va_arg(args, long int);
is_neg = 0;

/* Handle negative numbers */
if (input_int < 0)
{
int_digit = input_int * -1;
buf_i = hand_buff(buffer, '-', buf_i);
is_neg = 1;
}
else
{
int_digit = input_int;
}

/* Calculate the number of digits in the integer */
int_tmp = int_digit;
dvs = 1;

/* Calculate the divisor to extract digits of the integer */
while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}

for (a = 0; dvs > 0; dvs /= 10, a++)
{
buf_i = hand_buff(buffer, ((int_digit / dvs) % 10) + '0', buf_i);
}
/* Return the total number of integers printed,
 * negative numbers included.
 */
return (a + is_neg);
}
