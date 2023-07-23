#include "main.h"

/**
 * _printf - function that prints
 *
 * @format : character string
 *
 * Return: return
 */

int _printf(const char *format, ...)
{
	int a = 0;
	va_list ap;

	char *b;
	char *c;

	prm_st prm = PARAMS_INIT;

	va_start(ap, format);
	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (!format[2] && format[1] == ' ' && format[0] == '%')
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		init_prmrs(&prm, ap);
		if (*b != '%')
		{
			a = a + _putchar(*b);
			continue;
		}
		c = b;
		b++;
		while (_flag(b, &prm))
		{
			b++;
		}
		b = _width(b, &prm, ap);
		b = _precision(b, &prm, ap);
		if (_modifier(b, &prm))
			b++;
		if (!_specifier(b))
			a = a + print_f_t(c, b
					, prm.l_m || prm.h_m ? b - 1 : 0);
		else
			a = a + get_print_func(b, ap, &prm);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (a);
}
