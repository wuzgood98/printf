#include "main.h"

/**
 * spec_func_count - return the number of specifiers.
 * @str: specifier.
 * @idx: index of the specifier.
 *
 * Return: number of specifiers.
 */
int spec_func_count(const char *str, int idx)
{
	dict_t lookup[] = {
		{"c", print_char}, {"s", print_string},
		{"%", print_pctg}, {"l", print_pctg},
		{"h", print_pctg}, {" %", print_pctg},
		{"d", print_int}, {"i", print_int},
		{"b", print_binary}, {"u", print_unsigned_int},
	};
	int index = 0, temp_idx, count = 0;

	temp_idx = idx;
	while (lookup[index].spec)
	{
		if (str[idx] == lookup[index].spec[count])
		{
			if (lookup[index].spec[count + 1] != '\0')
				idx++, count++;
			else
				break;
		}
		else
		{
			count = 0;
			index++;
			idx = temp_idx;
		}
	}
	return (count);
}
