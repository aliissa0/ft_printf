/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:30:49 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 16:41:00 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrs(char const *s)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 0;
	while (s[i])
	{
		check = write(1, &s[i], 1);
		if (check == -1)
			return (-1);
		count = count + check;
		i++;
	}
	return (count);
}

int	ft_putchars(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_char(int c)
{
	int	count;

	count = ft_putchars(c);
	return (count);
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	if (!str)
		str = "(null)";
	i = 0;
	count = 0;
	while (str[i])
	{
		ft_addreturn(&count, ft_putchars(str[i]));
		i++;
	}
	return (count);
}
