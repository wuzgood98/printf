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
		{"%", print_pctg}, {"l", print_pctg}, {"h", print_pctg},
		{" %", print_pctg},
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
