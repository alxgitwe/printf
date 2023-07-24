#include "main.h"

/**
 * g_specifier - function
 *
 * @str : char
 *
 * Return: return
 */


int (*g_specifier(char *str))(va_list ap, prm_st *prm)
{
	spcfier_t spcfier[] = {
		{"c", print_c},
		{"d", print_i},
		{"i", print_i},
		{"s", print_s},
		{"%", print_p},
		{"b", print_b},
		{"o", print_o},
		{"u", print_ud},
		{"x", print_h},
		{"p", print_ae},
		{"S", print_ss},
		{"r", print_rv},
		{"R", p_rot13},
		{NULL, NULL}
	};
	int a = 0;

	while (spcfier[a].spcfier)
	{
		if (*str == spcfier[a].spcfier[0])
		{
			return (spcfier[a].f);
		}
		a++;
	}
	return (NULL);

}



/**
 * g_print_f - function
 *
 * @str : char
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int g_print_f(char *str, va_list ap, prm_st *prm)
{
	int (*f)(va_list, prm_st *) = g_specifier(str);

	if (f)
		return (f(ap, prm));
	return (0);
}





/**
 * _flag - function
 *
 * @str : char
 *
 * @prm : struct
 *
 * Return: return
 */

int _flag(char *str, prm_st *prm)
{
	int a = 0;

	switch (*str)
	{
		case '+':
			a = prm->plus_f = 1;
			break;
		case ' ':
			a = prm->space_f = 1;
			break;
		case '#':
			a = prm->hashtag_f = 1;
			break;
		case '-':
			a = prm->minus_f = 1;
			break;
		case '0':
			a = prm->zero_f = 1;
			break;
	}
	return (a);
}


/**
 * _modifier - function
 *
 * @str : char
 *
 * @prm : struct
 *
 * Return: return
 */

int _modifier(char *str, prm_st *prm)
{
	int a = 0;

	switch (*str)
	{
		case 'h':
			a = prm->h_m = 1;
			break;
		case 'l':
			a = prm->l_m = 1;
			break;
	}
	return (a);
}



/**
 * _width - function
 *
 * @str : char
 *
 * @prm : struct
 *
 * @ap : argument
 *
 * Return: return
 */

char *_width(char *str, prm_st *prm, va_list ap)
{
	int a = 0;

	if (*str == '*')
	{
		a = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			a = a * 10 + (*str++ - '0');
	}
	prm->width = a;
	return (str);

}





