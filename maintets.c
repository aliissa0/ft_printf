//cc maintets.c libftprintf.a -I. -Ilibft -o test

#include "ft_printf.h"
#include <stdio.h>
int main()
{
	char c = 'x';
	char *str = "hello world this is a test";
	ft_printf("%#X\n", 424967295);
	printf("%#X\n", 424967295);
}
