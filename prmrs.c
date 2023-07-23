#include "main.h"

/**
 * init_prmrs - function
 *
 * @prm : struct
 *
 * @ap : argument
 *
 * Return: void
 */

void init_prmrs(prm_t *prm, va_list ap)
{
	prm->unsn = 0;
	prm->plus_f = 0;
	prm->space_f = 0;
	prm->hashtag_f = 0;
	prm->zero_f = 0;
	prm->minus_f = 0;
	prm->width = 0;
	prm->precision = UINT_MAX;
	prm->h_m = 0;
	prm->l_m = 0;
	(void)ap;

}

