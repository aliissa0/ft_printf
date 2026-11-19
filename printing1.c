/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:04:02 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/19 13:19:47 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_flag flag, int c)
{
	int	width;
	int	count;

	width = flag.width;
	count = 0;
	if (flag.minus == 1)
	{
		ft_addreturn(&count, ft_putchars(c));
		ft_addreturn(&count, ft_putcharn(' ', width - 1));
	}
	else
	{
		ft_addreturn(&count, ft_putcharn(' ', width - 1));
		ft_addreturn(&count, ft_putchars(c));
	}
	return (count);
}

int	ft_print_str(t_flag flag, char const *str)
{
	int	count;
	int	len;

	if (!str)
		str = "(null)";
	count = 0;
	len = (int) ft_strlen(str);
	if (flag.prec != -1 && flag.prec < len)
		len = flag.prec;
	if (flag.minus == 1)
	{
		ft_addreturn(&count, ft_putstrs(str, len));
		ft_addreturn(&count, ft_putcharn(' ', flag.width - len));
	}
	else
	{
		ft_addreturn(&count, ft_putcharn(' ', flag.width - len));
		ft_addreturn(&count, ft_putstrs(str, len));
	}
	return (count);
}

