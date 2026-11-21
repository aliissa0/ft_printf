/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 22:53:04 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 20:30:02 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_isspec(char c)
{
	char	specifier[9];
	int		i;

	specifier[0] = 'c';
	specifier[1] = 's';
	specifier[2] = 'p';
	specifier[3] = 'd';
	specifier[4] = 'i';
	specifier[5] = 'u';
	specifier[6] = 'x';
	specifier[7] = 'X';
	specifier[8] = '\0';
	i = 0;
	while (specifier[i])
	{
		if (c == specifier[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isflag(char c)
{
	char	flags[6];
	int		i;

	flags[0] = '-';
	flags[1] = '+';
	flags[2] = '#';
	flags[3] = ' ';
	flags[4] = '0';
	flags[5] = '\0';
	i = 0;
	while (flags[i])
	{
		if (c == flags[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_setprec(t_flag *flag, char const *str, int *i)
{
	if (str[*i] == '.')
	{
		*i = *i + 1;
		flag->prec = 0;
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				flag->prec = flag->prec * 10 + (str[*i] - '0');
				*i = *i + 1;
			}
		}
	}
	if (ft_isspec(str[*i]))
	{
		flag->speci = str[*i];
		*i = *i + 1;
	}
}

int	ft_ischar(int c)
{
	if (c == 'c' || c == 's')
		return (1);
	return (0);
}
