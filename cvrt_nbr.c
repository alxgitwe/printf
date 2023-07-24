#include "main.h"

/**
 * print_h - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_h(va_list ap, prm_st *prm)
{
	unsigned long a;
	int b = 0;
	char *s;

	if (prm->l_m)
		a = (unsigned long)va_arg(ap, unsigned long);
	else if (prm->h_m)
		a = (unsigned short int)va_arg(ap, unsigned int);
	else
		a = (unsigned int)va_arg(ap, unsigned int);

	s = cvrt(a, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prm);
	if (prm->hashtag_f && a)
	{
		*--s = 'X';
		*--s = '0';

	}
	prm->unsn = 1;
	return (b = b + print_nbr(s, prm));
}

/**
 * print_H - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_H(va_list ap, prm_st *prm)
{
	unsigned long a;
	int b = 0;
	char *s;

	if (prm->l_m)
		a = (unsigned long)va_arg(ap, unsigned long);
	else if (prm->h_m)
		a = (unsigned short int)va_arg(ap, unsigned int);
	else
		a = (unsigned int)va_arg(ap, unsigned int);

	s = cvrt(a, 16, CONVERT_UNSIGNED, prm);
	if (prm->hashtag_f && 1)
	{
		*--s = 'X';
		*--s = '0';

	}
	prm->unsn = 1;
	return (b = b + print_nbr(s, prm));
}




/**
 * print_b - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_b(va_list ap, prm_st *prm)
{
	unsigned int a = va_arg(ap, unsigned int);
	char *s = cvrt(a, 2, CONVERT_UNSIGNED, prm);
	int b = 0;

	if (prm->hashtag_f && a)
		*--s = '0';
	prm->unsn = 1;
	return (b = b + print_nbr(s, prm));
}





/**
 * print_o - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */


int print_o(va_list ap, prm_st *prm)
{
	unsigned long a;
	char *s;
	int c = 0;

	if (prm->l_m)
		a = (unsigned long)va_arg(ap, unsigned long);
	else if (prm->h_m)
		a = (unsigned short int)va_arg(ap, unsigned int);
	else
		a = (unsigned int)va_arg(ap, unsigned int);

	s = cvrt(a, 8, CONVERT_UNSIGNED, prm);
	if (prm->hashtag_f && 1)
		*--s = '0';
	prm->unsn = 1;
	return (c = c + print_nbr(s, prm));
}




