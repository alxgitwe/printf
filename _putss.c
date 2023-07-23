#include "main.h"

/**
 * puts - function
 *
 * @stri : char
 *
 * Return: return
 */


int puts(char *stri)
{
	char *s = stri;

	while (*stri)
		putchar(*stri++);
	return (stri - a);

}





/**
 * _putchar - function
 *
 * @chr : int
 *
 * Return: return
 */

int _putchar(int chr)
{
	static int a;
	static char[OUTPUT_BIF_SIZE];

	if (chr == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}

	if (chr != BUF_FLUSH)
		buf[i++] = chr;
	return (1);
}

