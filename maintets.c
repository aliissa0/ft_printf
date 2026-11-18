//cc maintets.c libftprintf.a -I. -Ilibft -o test

#include "ft_printf.h"
#include <stdio.h>
int main()
{
	char c = 'x';
	char str[] = "hello";
	ft_printf("%.d", 0);
	printf("%.d", 0);
}