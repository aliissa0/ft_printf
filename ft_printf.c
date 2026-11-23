/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 14:50:19 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 23:43:23 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_addreturn(int *count, int re)
{
	if (*count == -1)
		return ;
	if (re == -1)
	{
		*count = -1;
		return ;
	}
	*count = *count + re;
}

int	ft_callprint(va_list *lst, char speci)
{
	int	count;

	count = 0;
	if (speci == 'c')
		count = ft_print_char(va_arg(*lst, int));
	else if (speci == 's')
		count = ft_print_str(va_arg(*lst, char *));
	else if (speci == 'd' || speci == 'i')
		count = ft_print_nb(va_arg(*lst, int));
	else if (speci == 'p')
		count = ft_print_add((unsigned long) va_arg(*lst, void *));
	else if (speci == 'x')
		count = ft_print_hexl(va_arg(*lst, unsigned int));
	else if (speci == 'X')
		count = ft_print_hexu(va_arg(*lst, unsigned int));
	else if (speci == 'u')
		count = ft_print_uns(va_arg(*lst, unsigned int));
	else if (speci == '%')
		count = ft_print_char('%');
	return (count);
}

int	ft_handlemod(va_list *lst, char const *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_addreturn(&count, ft_putchars(str[i]));
			i++;
		}
		else if (str[i + 1])
		{
			ft_addreturn(&count, ft_callprint(lst, str[i + 1]));
			i += 2;
		}
		else
			break ;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		count;

	va_start(lst, str);
	count = ft_handlemod(&lst, str);
	va_end(lst);
	return (count);
}
