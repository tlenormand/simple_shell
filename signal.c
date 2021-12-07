#include "main.h"

/**
 * ctrl_c - catch the signal from ^C
 * @i: signal from ^C (2)
 */

void ctrl_c(int i)
{
	(void) i;
	_puts_string("\n$ ");
}
