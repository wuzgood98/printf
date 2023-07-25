#include "main.h"

/**
 * displayhoct - Prints a long decimal number
 * in octal.
 *
 * @args: Input argument list containing the
 * long decimal number to print.
 * @buffer: Buffer pointer where the output
 * will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of characters printed.
 */
int displayhoct(va_list args, char *buffer, unsigned int buf_i)
{
short int input_int, a, is_neg, cnt, is_first;
char  *bin, *octal;

input_int = va_arg(args, int);
is_neg = 0;

if (input_int == 0)
{
/* Handle the special case of input_int being 0 */
buf_i = hand_buff(buffer, '0', buf_i);
return (1);
}

if (input_int < 0)
{
/* Handle negative numbers by converting to
 * two's complement.
 */
input_int = (input_int * -1) - 1;
is_neg = 1;
}

/* Convert the input number to a binary representation */
bin = malloc(sizeof(char) * (16 + 1));
bin = init_bin(bin, input_int, is_neg, 16);

/* Convert the binary representation to octal */
octal = malloc(sizeof(char) * (6 + 1));
octal = init_oct(octal, bin);

/* Print the octal representation and count
 * the number of characters printed.
 */
for (is_first = a = cnt = 0; octal[a]; a++)
{
/* Skip leading zeros in the octal representation */
if (octal[a] != '0' && is_first == 0)
is_first = 1;

if (is_first)
{
/* Print the octal character and update the count */
buf_i = hand_buff(buffer, octal[a], buf_i);
cnt++;
}
}

free(bin);
free(octal);
return (cnt);
}
