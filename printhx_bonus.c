/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhx_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:42:09 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 12:48:04 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_hx1(t_flag flag, char *nb, int cas)
{
	int	count;
	int	len;
	int	tlen;
	int	plen;
	
	count = 0;
	plen = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	if (flag.hash == 1)
	{
		ft_addreturn(&count, ft_print_prefix(cas));
		plen = 2;
	}
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len + plen)));
	return (count);
}

int	ft_print_hx1_1(t_flag flag, char *nb, int cas)
{
	int	count;
	int	len;
	int	tlen;
	int	plen;
	
	count = 0;
	plen = 0;
	if (flag.hash)
		plen = 2;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len + plen)));
	if (flag.hash == 1)
		ft_addreturn(&count, ft_print_prefix(cas));
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	return (count);
}

int	ft_print_hx2(t_flag flag, char *nb, int cas)
{
	int		count;
	int		len;

	count = 0;
	len = (int) ft_strlen(nb);
	if (flag.hash)
	{
		ft_addreturn(&count, ft_print_prefix(cas));
		ft_addreturn(&count, ft_putcharn('0', flag.width - len - 2));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	else
	{	
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	return (count);
}

int	ft_print_hexl(t_flag flag, unsigned int nbr)
{
	char	*nb;
	int		count;

	count = 0;
	if (nbr == 0)
		flag.hash = 0;
	nb = ft_ltoa_base(nbr, "0123456789abcdef");
	if (!nb)
		return (-1);
	if (nbr == 0 && flag.prec == 0)
		nb[0] = 0;
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_hx1(flag, nb, 0));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_hx2(flag, nb, 0));
	else
		ft_addreturn(&count, ft_print_hx1_1(flag, nb, 0));
	free(nb);
	return (count);
}

int	ft_print_hexu(t_flag flag, unsigned int nbr)
{
	char	*nb;
	int		count;

	count = 0;
	if (nbr == 0)
		flag.hash = 0;
	nb = ft_ltoa_base(nbr, "0123456789ABCDEF");
	if (!nb)
		return (-1);	
	if (nbr == 0 && flag.prec == 0)
		nb[0] = 0;
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_hx1(flag, nb, 1));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_hx2(flag, nb, 1));
	else
		ft_addreturn(&count, ft_print_hx1_1(flag, nb, 1));
	free(nb);
	return (count);
}
