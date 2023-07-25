#include "main.h"

/**
 * printlngoct - prints the octal representation
 * of long decimals.
 * @args: list of arguments.
 * @buffer: pointer to the buffer where output
 * will be stored.
 * @buf_i: buffer index.
 *
 * Return: the number of chars printed.
 */

int printlngoct(va_list args, char *buffer, unsigned int buf_i)
{
/* variable declarations */
char *octal;
char *binary;
long int input_int, a, is_neg, count, first_dig;

input_int = va_arg(args, long int);
is_neg = 0;
if (input_int == 0)
{
buf_i = hand_buff(buffer, '0', buf_i);
return (1);  
}
if (input_int < 0)
{
input_int = (input_int * -1) -1;
is_neg = 1;
}

binary = malloc(sizeof(char) * (64 + 1));
binary = fill_bin_array(binary, input_int, is_neg, 64);
octal = malloc(sizeof(char) * (22 + 1));
octal = fill_lng_oct_arr(binary, octal);
/* Print the octal representation and count
 * the number of characters printed
 */
for (first_dig = a = count = 0; octal[a]; a++)
{   
if (octal[a] != '0' && first_dig == 0)
first_dig = 1;
if (first_dig)
{
buf_i = hand_buff(buffer, octal[a], buf_i);
count++
}
}
free(binary);
free(octal);
return (count);
}
