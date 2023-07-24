#include "main.h"

/**
 * print_c - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_c(va_list ap, prm_st *prm)
{
	char pchar = ' ';
	unsigned int p = 1, a = 0, b = va_arg(ap, int);

	if (prm->minus_f)
		a = a + _putchar(b);
	while (p++ < prm->width)
		a = a + _putchar(pchar);
	if (!prm->minus_f)
		a = a + _putchar(b);
	return (a);

}

/**
 * print_i - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_i(va_list ap, prm_st *prm)
{
	long a;

	if (prm->l_m)
		a = va_arg(ap, long);
	else if (prm->h_m)
		a = (short int)va_arg(ap, int);
	else
		a = (int)va_arg(ap, int);
	return (print_nbr(cvrt(a, 10, 0, prm), prm));
}

/**
 * print_s - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_s(va_list ap, prm_st *prm)
{
	char *s = va_arg(ap, char *);
	char pchar = ' ';
	unsigned int p = 0;
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int c;

	(void) prm;

	switch ((int)(!s))

	case 1:
		s = NULL_STRING;
	c = p = _strlen(s);
	if (prm->precision < p)
		c = p = prm->precision;

	if (prm->minus_f)
	{
		if (prm->precision != UINT_MAX)
			for (b = 0; b < p; b++)
				a = a + _putchar(*s++);
		else
			a = a + _puts(s);
	}
	while (c++ < prm->width)
		a = a + _putchar(pchar);
	if (!prm->minus_f)
	{
		if (prm->precision != UINT_MAX)
			for (b = 0; b < p; b++)
				a = a + _putchar(*s++);
		else
			a = a + _puts(s);
	}
	return (a);


}


/**
 * print_p - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_p(va_list ap, prm_st *prm)
{
	(void)ap;
	(void)prm;

	return (_putchar('%'));
}

/**
 * print_ss - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_ss(va_list ap, prm_st *prm)
{
	char *s = va_arg(ap, char *);
	char *h;
	int a = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			a = a + _putchar('\\');
			a = a + _putchar('X');
			h = cvrt(*s, 16, 0, prm);
			if (!h[1])
				a = a + _putchar('0');
			a = a + _puts(h);
		}
		else
		{
			a = a + _putchar(*s);
		}
}return (a);
}






