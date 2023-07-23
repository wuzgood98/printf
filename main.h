#ifndef _main_h_
#define _main_h_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct dictionary - struct for printer functions
 * @spec: specifier
 * @print: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct dictionary
{
	char *spec;
	int (*print)(va_list, char *, unsigned int);
} dict_t;

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_char(va_list args, char *buffer, unsigned int idx);
int display_buff(char *buffer, unsigned int bytes);
int (*spec_func(const char *str, int idx))(va_list, char *, unsigned int);
int spec_func_count(const char *str, int idx);
unsigned int hand_buff(char *buffer, char c, unsigned int buf_i);
int print_string(va_list args, char *buffer, unsigned int buf_i);
int print_pctg(va_list args __attribute__((unused)), char *b, unsigned int b_i);
int print_int(va_list args, char *buffer, unsigned int buf_i);

#endif
