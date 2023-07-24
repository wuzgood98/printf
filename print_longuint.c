#include "main.h"

/**
 * printluint - prints unsigned long integers from the arg.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
 * @buf_i: buffer index - current position in the buffer.
 *
 * Return: the number of chars printed.
 */

int printluint(va_list args, char *buffer, unsigned int buf_i)
{
long unsigned int int_digit, int_tmp, a, dvs;

/* Get the arguments from va_list */
int_digit = va_arg(args, unsigned long int);
int_tmp = int_digit; 
dvs = 1;
/* Calculate the divisor (dvs) to extract digits
 * of the unsigned integer
 */
while (int_tmp > 9)
{
dvs *= 10;
int_tmp /= 10;
}
/* Print the digits of the unsigned integer one by one */
for (a = 0; dvs > 0; dvs /= 10, a++)
{
/* Extract each digit and convert it to character
 * ('0' to '9')
 */
buf_i = hand_buff(buffer, ((int_digit / dvs) % 10) + '0', buf_i);
}
/* Return the total number of chars printed */
return (a);
}
