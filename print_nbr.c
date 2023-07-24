#include "main.h"

/**
 * _isdigit - function
 *
 * @a : int
 *
 * Return: return
 */

int _isdigit(int a)
{
	return (a >= '0' && a <= '9');
}

/**
 * _strlen - function
 *
 * @str : char
 *
 * Return: return
 */

int _strlen(char *str)
{
	int a = 0;

	while (*str++)
		a++;
	return (a);
}



/**
 * print_nbr - function
 *
 * @s : char
 *
 * @prm : struct
 *
 * Return: return
 */

int print_nbr(char *s, prm_st *prm)
{
	unsigned int a = _strlen(s);
	int b = (!prm->unsn && *s == '-');

	if (!prm->precision && *s == '0' && !str[1])
		s = "";
	if (b)
	{
		s++;
		a--;
	}
	if (prm->precision != UINT_MAX)
		while (a++ < prm->precision)
			*--s = '0';
	if (b)
		*--s = '-';

	if (!prm->minus_f)
		return (print_nrs(s, prm));
	else
		return (print_nls(s, prm));
}


/**
 * print_nrs - function
 *
 * @s : char
 *
 * @prm : struct
 *
 * Return: return
 */


int print_nrs(char *s, prm_st *prm)
{
	unsigned int a = 0;
	unsigned int b;
	unsigned int c;
	unsigned int d = _strlen(s);
	char pchar = ' ';

	if (prm->zero_f && !prm->minus_f)
		pchar = '0';
	b = c = (!prm->unsn && *s == '-');
	if (b && d < prm->width && pchar == '0' && !prm->minus_f)
		s++;
	else
		b = 0;
	if ((prm->plus_f && prm->space_f && !c))
		d++;
	if (b && pchar == '0')
		a = a + pchar ('0');
	if (prm->plus_f && !c && pchar == '0' && !prm->unsn)
		a = a + _putchar('+')
	else if (!prm->plus_f && prm->space_f && !c && !prm->unsn && prm->zero_f)
		a = a + _putchar(' ');
	while (d++ < prm->width)
		a = a + _putchar(pchar);
	if (b && pchar == ' ')
		a = a + _putchar('-');
	if (prm->plus_f && !c && pchar == ' ' && !prm->unsn)
		a = a + _putchar('+');
	else if (!prm->plus_f && prm->space_f && !C && !prm->unsn && !prm->zero_f)
		a = a + _putchar(' ');
	a = a + _puts(s);
	return (a);
}

/**
 * print_nls - function
 *
 * @s : char
 *
 * @prm : struct
 *
 * Return: return
 */

int print_nls(char *s, prm_st *prm)
{
	unsigned int a = 0;
	unsigned int b;
	unsigned int c;
	unsigned int d = _strlen(s);
	char pchar = ' ';

	if (prm->zero_f && !prm->minus_f)
		pchar = '0';
	b = c = (!prm->unsn && *s == '-');
	if (b && d < prm->width && pchar == '0' && !prm->minus_f)
		s++;
	else
		b = 0;
	if ((prm->plus_f && !prm->unsn && !c))
		a = a + _putchar('+'), d++;
	else if (prm->space_f && !c && !prm->unsn)
		a = a + _putchar(' '), d++;
	a = a + _puts(s);
	while (d++ < prm->width)
		a = a + _putchar(pchar);
	return (a);
}


