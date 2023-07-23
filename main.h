#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct prm - struct
 *
 * @unsn : int
 * @plus_f : int
 * @space_f : int
 * @hashtag_f : int
 * @zero_f : int
 * @minus_f : int
 * @width : int
 * @precision : int
 * @h_m : int
 * @l_m : int
 */

typedef struct prm
{
	unsigned int unsn : 1;
	unsigned int plus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int minus_f : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_m : 1;
	unsigned int l_m : 1;
} prm_st;

/**
 * struct spcfier - struct
 *
 * @spcfier : char
 * @f : function
 */
typedef struct spcfier
{
	char *spcfier;
	int (*f)(va_list, prm_st *);

} spcfier_t;

int _printf(const char *format, ...);
int _putchar(int c);
int _puts(char *strg);
int print_char (va_list ap, prm_st *prm);
int print_string(va_list ap, prm_st *prm);
int print_percent(va_list ap, prm_st *prm);
void init_prmrs(prm_t *prm, va_list ap);

#endif
