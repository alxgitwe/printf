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
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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

/* _putss.c */
int _putchar(int c);
int _puts(char *strg);

/* nbr.c */
char *cvrt(long int nm, int be, int fs, prm_st *prm);
int print_ud(va_list ap, prm_st *prm);
int print_ae(va_list ap, prm_st *prm);

/*  specifiers.c  */
int (*g_specifier(char *str))(va_list ap, prm_st *prm);
int g_print_f(char *str, va_list ap, prm_st *prm);
int _flag(char *str, prm_st *prm);
int _modifier(char *str, prm_st *prm);
char *_width(char *str, prm_st *prm, va_list ap);

/* print_f.c */
int print_c(va_list ap, prm_st *prm);
int print_i(va_list ap, prm_st *prm);
int print_s(va_list ap, prm_st *prm);
int print_p(va_list ap, prm_st *prm);
int print_ss(va_list ap, prm_st *prm);

/* cvrt_nbr.c */
int print_h(va_list ap, prm_st *prm);
int print_H(va_list ap, prm_st *prm);
int print_b(va_list ap, prm_st *prm);
int print_o(va_list ap, prm_st *prm);

/* s_print.c */
int print_f_t(char *st, char *sp, char *et);
int print_rv(va_list ap, prm_st *prm);
int p_rot13(va_list ap, prm_st *prm);

/* print_nbr.c */
int _isdigit(int a);
int _strlen(char *str);
int print_nbr(char *s, prm_st *prm);
int print_nrs(char *s, prm_st *prm);
int print_nls(char *s, prm_st *prm);

/* prmrs.c */
void init_prmrs(prm_st *prm, va_list ap);

/* _printf.c */
int _printf(const char *format, ...);

/* string_f.c */
char *_precision(char *s, prm_st *prm, va_list ap);







#endif
