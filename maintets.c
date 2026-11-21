//cc maintets.c libftprintf.a -I. -Ilibft -o test

#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int a;
	int b;
	char c = 'x';
	char *str = "hello world this is a test";
	a = ft_printf("");
	printf(": %d : \n", a);
	b = printf("");
	printf(" : %d : \n", b);
}
