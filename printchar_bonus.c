/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:04:02 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 12:47:54 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_putchars(char c)
{
	return (write(1, &c, 1));
}

int ft_putstrs(char const *s, int len)
{
	int	i;
	int	count;
	int check;

	i = 0;
	count = 0;
	check = 0;
	while (i < len && s[i])
	{
		check = write(1, &s[i], 1);
		if (check == -1)
			return (-1);
		count = count + check;
		i++;
	}
	return (count);
}

int ft_putcharn(char c, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (write(1, &c, 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

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
