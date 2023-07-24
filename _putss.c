#include "main.h"

/**
 * _puts - function
 *
 * @stri : char
 *
 * Return: return
 */


int _puts(char *stri)
{
	char *s = stri;

	while (*stri)
		putchar(*stri++);
	return (stri - s);

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
	static char buf[OUTPUT_BUF_SIZE];

	if (chr == BUF_FLUSH || a >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}

	if (chr != BUF_FLUSH)
		buf[a++] = chr;
	return (1);
}

