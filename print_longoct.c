#include "main.h"

/**
 * printlngoct - prints the octal representation of long decimals.
 * @args: list of arguments.
 * @buffer: pointer to the buffer.
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
binary =  
 
 
