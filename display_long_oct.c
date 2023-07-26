#include "main.h"

/**
 * displayloct - Prints long decimal number
 * in octal.
 * @args: Input argument list containing
 * the long decimal number to print.
 * @buffer: Buffer pointer where the output
 * will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of characters printed.
 */

int displayloct(va_list args, char *buffer, unsigned int buf_i)
{
long int input_int;
char *octal, *bin;
unsigned int is_neg, a, cnt, is_first;

/* Retrieve the long decimal number from
 * the argument list
 */
input_int = va_arg(args, long int);
is_neg = 0;

/* Handle special case: if the input
 * number is 0
 */
if (input_int == 0)
{
buf_i = hand_buff(buffer, '0', buf_i);
return (1);
}

/* Handle negative numbers by converting
 * them to 2's complement
 */
if (input_int < 0)
{
input_int = (input_int * -1) - 1;
is_neg = 1;
}

/* Allocate memory for binary and octal arrays */
bin = malloc(sizeof(char) * (64 + 1));
bin = init_bin(bin, input_int, is_neg, 64);
octal = malloc(sizeof(char) * (22 + 1));

/* Convert binary to octal representation */
octal = init_oct(octal, bin);

/* Print the octal number, omitting leading zeros */
for (is_first = a = cnt = 0; octal[a]; a++)
{
if (octal[a] != '0' && is_first == 0)
is_first = 1;
if (is_first)
{
buf_i = hand_buff(buffer, octal[a], buf_i);
cnt++;
}		}
}
/* free allocated memory */
free(bin);
free(octal);
return (cnt);
}
