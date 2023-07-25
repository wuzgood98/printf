#include "main.h"

/**
 * displayhupx - Prints a short decimal
 * in hexadecimal.
 * @args: Input argument list containing
 * the short decimal to print.
 * @buffer: Buffer pointer where the output
 * will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of chars printed.
 */

int displayhupx(va_list args, char *buffer, unsigned int buf_i)
{
short int input_int, int_digit, int_tmp, a, dvs, is_neg;
char *hex, *bin;

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
 * two's complement
 */
input_int = (input_int * -1) - 1;
is_neg = 1;
}

/* Convert the input number to a binary
 * representation
 */
bin = malloc(sizeof(char) * (16 + 1));
bin = init_bin(bin, input_int, is_neg, 16);

/* Convert the binary representation to
 * hexadecimal
 */
hex = malloc(sizeof(char) * (4 + 1));
hex = init_hex(hex, bin, 4, 1);

/* Print the hexadecimal representation and
 * count the number of characters printed
 */
for (int_tmp = int_digit = a = dvs = 0; hex[a]; a++)
	{
/* Skip leading zeros in the hexadecimal
 * representation
 */
if (hex[a] != '0' && int_tmp == 0)
int_tmp = 1;

if (int_tmp)
{
/* Print the hexadecimal character and update
 * the count.
 */
buf_i = hand_buff(buffer, hex[a], buf_i);
dvs++;
}
}

free(bin);
free(hex);
return (dvs);
}
