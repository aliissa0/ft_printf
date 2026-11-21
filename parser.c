/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:30:42 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 02:45:55 by aliissa          ###   ########.fr       */
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

int	ft_callprint(va_list *lst, t_flag flag)
{
	int	count;

	count = 0;
	if (flag.speci == 'c')
		count = ft_print_char(flag, va_arg(*lst, int));
	else if (flag.speci == 's')
		count = ft_print_str(flag, va_arg(*lst, char *));
	else if (flag.speci == 'd' || flag.speci == 'i')
		count = ft_print_nb(flag, va_arg(*lst, int));
	else if (flag.speci == 'p')
		count = ft_print_add(flag, (unsigned long) va_arg(*lst, void *));
	else if (flag.speci == 'x')
		count = ft_print_hexl(flag, va_arg(*lst, unsigned int));
	else if (flag.speci == 'X')
		count = ft_print_hexu(flag, va_arg(*lst, unsigned int));	
	else if (flag.speci == 'u')
		count = ft_print_uns(flag, va_arg(*lst, unsigned int));
	return (count);
}

int	ft_handlemod(va_list *lst, char const *str)
{
	t_flag	newflag;
	int		count;
	int		i;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_addreturn(&count, ft_putchars(str[i]));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_parser(str, &i, &newflag);
			ft_addreturn(&count, ft_callprint(lst, newflag));
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_addreturn(&count, ft_putchars('%'));
			i += 2;
		}
	}
	return (count);
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
