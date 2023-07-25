#include "main.h"

/**
 * fill_lng_oct_arr - converts binary array to
 * long octal number.
 * @bin: array containing the binary representation.
 * @octal: array where is stored the octal.
 *
 * Return: pointer to octal array.
 */

char *fill_lng_oct_arr(char *bin, char *octal)
{
int ap, a, b, i_oct, lim;

octal[22] = '\0';
for (a = 63, i_oct = 21; a >= 0; a--, i_oct--)
{
/* Find the number of bits to process for the current
 * octal digit
*/ 
if (a > 0)
lim = 4;
else
lim = 1;
/* calc the decimal value for the current octal digit */
for (ap = 0, b = 1; b <= lim; b *= 2, a--)
ap = ((bin[a] - '0') * b) + ap;
/* correct the index after the loop */
a++;
/* Store the decimal value as an ASCII character
 *  in the octal array.
 */
octal[i_oct] = ap + '0';
}
return (octal);
}
