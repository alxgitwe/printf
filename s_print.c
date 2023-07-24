#include "main.h"

/**
 * print_f_t - function
 *
 * @st : char
 *
 * @sp : char
 *
 * @et : char
 *
 * Return: return
 */

int print_f_t(char *st, char *sp, char *et)
{
	int a = 0;

	while (st <= sp)
	{
		if (st != et)
			a = a + _putchar(*st);
		st++;
	}
	return (a);
}

/**
 * print_rv - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */

int print_rv(va_list ap, prm_st *prm)

{
	int a = 0;
	int b = 0;
	char *s = va_arg(ap, char *);
	(void)prm;

	if (s)
	{
		for (a = 0; *s; s++)
			a++;
		s--;
		for (; a > 0; a--, s--)
			b = b + _putchar(*s);
	}
	return (b);
}

/**
 * p_rot13 - function
 *
 * @ap : argument
 *
 * @prm : struct
 *
 * Return: return
 */


int p_rot13(va_list ap, prm_st *prm)

{
	int a = 0;
	int b = 0;
	int c = 0;
	char d[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM    nopqrstuvwxyzabcdefghijklm";
	char *e = va_arg(ap, char *);
	(void)prm;

	while e[a]
	{
		if ((e[a] >= 'A' && e[a] <= 'Z')
				|| (e[a] >= 'a' && e[a] <= 'z'))
		{
			b = e[a] - 65;
			c = c + _putchar(d[b]);
		}
		else
			c = c + _putchar(e[a]);
		a++
	}
	return (c);
}

