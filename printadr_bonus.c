/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printadr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:41:01 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 16:26:07 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_prefix(int up)
{
	int	count;

	count = 0;
	if (up)
		ft_addreturn(&count, ft_putstrs("0X", 2));
	else
		ft_addreturn(&count, ft_putstrs("0x", 2));
	return (count);
}

int	ft_print_add1(t_flag flag, char *add)
{
	int	count;
	int	len;

	count = 0;
	len = (int) ft_strlen(add) + 2;
	if (flag.minus == 1)
	{
		ft_addreturn(&count, ft_print_prefix(0));
		ft_addreturn(&count, ft_putstrs(add, len));
		ft_addreturn(&count, ft_putcharn(' ', flag.width - len));
	}
	else
	{
		ft_addreturn(&count, ft_putcharn(' ', flag.width - len));
		ft_addreturn(&count, ft_print_prefix(0));
		ft_addreturn(&count, ft_putstrs(add, len));
	}
	return (count);
}

int	ft_print_add(t_flag flag, unsigned long p)
{
	char	*add;
	int		count;

	if (p == 0)
	{
		flag.prec = -1;
		return (ft_print_str(flag, "(nil)"));
	}
	add = ft_ltoa_base(p, "0123456789abcdef");
	if (!add)
		return (-1);
	count = 0;
	ft_addreturn(&count, ft_print_add1(flag, add));
	free(add);
	return (count);
}

int	ft_print_uns(t_flag flag, unsigned int nbr)
{
	char	*nb;
	int		count;

	count = 0;
	nb = ft_ltoa_base(nbr, "0123456789");
	if (!nb)
		return (-1);
	if (nbr == 0 && flag.prec == 0)
		nb[0] = '\0';
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_nb1(flag, nb, 0));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_nb2(flag, nb, 0));
	else
		ft_addreturn(&count, ft_print_nb1_1(flag, nb, 0));
	free(nb);
	return (count);
}
