#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: a character string. Composed of zero or more directives.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{

	unsigned int cnt = 0, idx = 0, buf_i = 0;
	char *buffer;
	va_list args;
	int (*func)(va_list, char *, unsigned int);

	va_start(args, format), buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (!format || !buffer || (format[idx] == '%' && !format[idx + 1]))
		return (-1);
	if (!format[idx])
		return (0);
	for (idx = 0; format && format[idx]; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '\0')
			{
				display_buff(buffer, buf_i), free(buffer), va_end(args);
				return (-1);
			}
			else
			{
				func = spec_func(format, idx + 1);
				if (func == NULL)
				{
					if (format[idx + 1] == ' ' && !format[idx + 2])
						return (-1);
					hand_buff(buffer, format[idx], buf_i), cnt++, idx--;
				}
				else
				{
					cnt += func(args, buffer, buf_i);
					idx += spec_func_count(format, idx + 1);
				}
			} idx++;
		}
		else
			hand_buff(buffer, format[idx], buf_i), cnt++;
		for (buf_i = cnt; buf_i > BUFF_SIZE; buf_i -= BUFF_SIZE)
			;
	}
	display_buff(buffer, buf_i), free(buffer), va_end(args);
	return (cnt);
}
