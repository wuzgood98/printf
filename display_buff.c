#include "main.h"

/**
 * display_buff - displays the buffer
 * @buffer: pointer to the buffer.
 * @bytes: number of bytes to display.
 *
 * Return: number of bytes printed.
 */
int display_buff(char *buffer, unsigned int bytes)
{
	return (write(1, buffer, bytes));
}
