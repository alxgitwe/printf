#include "main.h"

/**
 * _precision - function
 *
 * @s : char
 *
 * @prm : struct
 *
 * @ap : argument
 *
 * Return: return
 */


char *_precision(char *s, prm_st *prm, va_list ap)
{
	int a = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		a = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			a = a * 10 + (*s++ - '0');
	}
	prm->precision = a;
	return (s);
}
