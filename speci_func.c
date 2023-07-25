#include "main.h"

/**
 * spec_func - chooses the correct function to perform the operation.
 * @str: argument as specifier.
 * @idx: index for the specifier.
 *
 * Return: pointer to the print function.
 */
int (*spec_func(const char *str, int idx))(va_list, char *, unsigned int)
{
	dict_t lookup[] = {
		{"c", print_char}, {"s", print_string},
		{"%", print_pctg}, {"l", print_pctg},
		{"h", print_pctg}, {" %", print_pctg},
		{"i", print_int}, {"d", print_int},
		{"b", print_binary}, {"u", print_unsigned_int},
		{"o", print_octal}, {"x", print_lower_hex},
		{"X", print_upper_hex}, {"S", print_S},
		{"p", print_address}, {" u", print_unsigned_int},
		{" o", print_octal}, {" x", print_lower_hex},
		{" X", print_upper_hex}, {"+X", print_upper_hex},
		{"+x", print_lower_hex}, {"+o", print_octal},
		{"#u", print_unsigned_int}, {"#i", print_int},
		{"#d", print_int}, {"#o", print_hash_oct},
		{"#x", print_hash_hexL}, {"#X", print_hash_hexU},
		{"+d", print_plus_int}, {"+i", print_plus_int},
		{"+u", print_unsigned_int}, {" i", print_space_int},
		{" d", print_space_int}, {" +i", print_plus_int},
		{" +d", print_plus_int}, {"+ i", print_plus_int},
		{"+ d", print_plus_int}, {"R", print_rot13},
		{"r", print_reverse}, {"ld", print_longint},
		{"li", print_longint}, {"lu", printluint},
		{"lo", printlngoct}, {"lX", displaylupx},
		{"hd", displayhint}, {"hi", displayhint},
		{"hu", displayhuint}, {"ho", displayhoct},
		{"hx", displayhhex},

		{NULL, NULL},
	};
	int index = 0, temp_idx, j = 0;

	temp_idx = idx;
	while (lookup[index].spec)
	{
		if (str[idx] == lookup[index].spec[j])
		{
			if (lookup[index].spec[j + 1] != '\0')
				idx++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			index++;
			idx = temp_idx;
		}
	}
	return (lookup[index].print);
}
