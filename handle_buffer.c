#include "main.h"

/**
 * hand_buff - concats the buffer characters.
 * @buffer: pointer to the buffer.
 * @c: character to concat.
 * @buf_i: index of the pointer to the buffer.
 *
 * Return: index of the pointer to the buffer.
 */
unsigned int hand_buff(char *buffer, char c, unsigned int buf_i)
{
	if (buf_i == BUFF_SIZE)
	{
		display_buff(buffer, buf_i);
		buf_i = 0;
	}
	buffer[buf_i] = c;
	buf_i++;
	return (buf_i);
}
