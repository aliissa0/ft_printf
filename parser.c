/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:30:42 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/18 16:41:29 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flag *new)
{ 
	new->minus = 0;
	new->zero = 0;
	new->plus = 0;
	new->space = 0;
	new->hash = 0;
	new->prec = -1;
	new->width = 0;
	new->speci = '\0';
}

void	ft_callprint(va_list *lst, t_flag flag)
{
	if (flag.speci == 'c')
		ft_print_char(flag, va_arg(*lst, int));
	else if (flag.speci == 's')
		ft_print_str(flag, va_arg(*lst, char *));
	else if (flag.speci == 'd' || flag.speci == 'i')
		ft_print_nb(flag, va_arg(*lst, int));
	else if (flag.speci == 'p')
	{
		/* code */
	}
	else if (flag.speci == 'x' || flag.speci == 'X')
	{
		/* code */
	}
	else if (flag.speci == 'u')
	{
		/* code */
	}
}

int	ft_handlemod(va_list *lst, char const *str)
{
	t_flag	newflag;
	int		i;
	
	i = 0;
	(void)lst;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_parser(str, &i, &newflag);
			ft_callprint(lst, newflag);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar_fd('%', 1);
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (1);
}

void	ft_parser(char const *str, int *i, t_flag *flag)
{
	ft_init_flags(flag);
	*i = *i + 1;
	while (ft_isflag(str[*i]))
	{
		if (str[*i] == '-')
			flag->minus = 1;
		else if (str[*i] == '0')
			flag->zero = 1;
		else if (str[*i] == '#')
			flag->hash = 1;
		else if (str[*i] == '+')
			flag->plus = 1;
		else if (str[*i] == ' ')
			flag->space = 1;
		*i = *i + 1;
	}
	while (ft_isdigit(str[*i]))
	{
		flag->width = flag->width * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
	ft_setprec(flag, str, i);
}
