#include "main.h"

/**
 * printlnghex - Prints a long decimal in hexadecimal.
 *
 * @args: Input argument list containing the
 * long integer to convert.
 * @buffer: Buffer pointer where the output will be stored.
 * @buf_i: Index for the buffer pointer.
 *
 * Return: Number of characters printed.
 */
int printlnghex(va_list args, char *buffer, unsigned int buf_i)
{
long int input_int, a, is_neg, count, first_dig;
char *hexadecimal, *binary;

input_int = va_arg(args, long int);
is_neg = 0;

if (input_int == 0)
{
/* Handle the special case of input_int being zero */
buf_i = hand_buff(buffer, '0', buf_i);
return (1);
}

if (input_int < 0)
{
/* Handle negative numbers by converting to two's
 * complement.
 */
input_int = (input_int * -1) - 1;
is_neg = 1;
}

/* Convert the input number to a binary representation */
binary = malloc(sizeof(char) * (64 + 1));
binary = init_bin(bin, input_int, is_neg, 64);

/* Convert the binary representation to hexadecimal */
hexadecimal = malloc(sizeof(char) * (16 + 1));
hexadecimal = init_hex(hex, bin, 16, 0);

/* Print the hexadecimal representation and count
 * the number of characters printed
 */
for (first_dig = a = count = 0; hexadecimal[a]; a++)
{
if (hexadecimal[a] != '0' && first_dig == 0)
first_dig = 1;

if (first_dig)
{
/* Print the hexadecimal character and update the count */
buf_i = hand_buff(buffer, hexadecimal[a], buf_i);
count++;
}
}

free(binary);
free(hexadecimal);

return (count);
}
