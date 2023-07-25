#include "main.h"

/**
 * fill_bin_array - Fills the binary representation
 * of the input number.
 * @bin: pointer to binary representation.
 * @int_digit: input number to convert to binary.
 * @is_neg: Flag indicating if number is negative.
 * @limit: size of the binary representation buffer
 * Return: pointer to the binary representation.
 */

char *fill_bin_array(char *bin, long int int_digit, int is_neg, int limit)
{
int a;
/* Initialize the binary array with '0's */
for (a = 0; a < limit; a++)
bin[a] = '0';
bin[limit] = '\0';
/* Convert the input number to binary */
for (a = limit - 1; int_digit > 1; a--)
{
if (int_digit == 2)
bin[a] = '0';
else
bin[a] = (int_digit % 2) + '0';
int_digit /= 2;
}
/* Handle is the last binary digit */
if (int_digit != 0)
bin[a] = '1';
/* Handle negative numbers with one's complement */
if (is_neg)
{
for (a = 0; bin[a]; a++)
if (bin[a] == '0')
bin[a] = '1';
else
bin[a] = '0';
}
return (bin);
}
