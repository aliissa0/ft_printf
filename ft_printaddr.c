/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:52:39 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 16:45:04 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_prefix(int up)
{
	int	count;

	count = 0;
	if (up)
		ft_addreturn(&count, ft_print_str("0X"));
	else
		ft_addreturn(&count, ft_print_str("0x"));
	return (count);
}

int	ft_print_add(unsigned long addr)
{
	char	*add;
	int		count;

	if (addr == 0)
	{
		return (ft_print_str("(nil)"));
	}
	count = 0;
	add = ft_ltoa_base(addr, "0123456789abcdef");
	if (!add)
		return (-1);
	count = 0;
	ft_addreturn(&count, ft_print_prefix(0));
	ft_addreturn(&count, ft_print_str(add));
	free(add);
	return (count);
}

int	ft_print_hexl(unsigned int addr)
{
	char	*nb;
	int		count;

	count = 0;
	nb = ft_ltoa_base(addr, "0123456789abcdef");
	if (!nb)
		return (-1);
	ft_addreturn(&count, ft_print_str(nb));
	free(nb);
	return (count);
}

int	ft_print_hexu(unsigned int addr)
{
	char	*nb;
	int		count;

	count = 0;
	nb = ft_ltoa_base(addr, "0123456789ABCDEF");
	if (!nb)
		return (-1);
	ft_addreturn(&count, ft_print_str(nb));
	free(nb);
	return (count);
}
