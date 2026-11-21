/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 12:39:49 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 12:52:09 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int ft_print_nb1(t_flag flag, char *nb, char sign)
{
    int count;
    int len;
    int	tlen;
	int	slen;
    
    count = 0;
	slen = 0;
    len = (int) ft_strlen(nb);
    tlen = 0;
    if (flag.prec != -1 && flag.prec > len)
        tlen = flag.prec - len;
    if (sign)
	{
        ft_addreturn(&count, ft_putchars(sign));
		slen = 1;
	}
    ft_addreturn(&count, ft_putcharn('0', tlen));
    ft_addreturn(&count, ft_putstrs(nb, len));
    ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len + slen)));
    return (count);
}

int	ft_print_nb1_1(t_flag flag, char *nb, char sign)
{
	int		count;
	int		len;
	int		tlen;
	int		slen;
	
	count = 0;
	slen = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (sign)
		slen = 1;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len + slen)));
	if (sign)
		ft_addreturn(&count, ft_putchars(sign));
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	return (count);
}

int	ft_print_nb2(t_flag flag, char *nb, char sign)
{
	int		count;
	int		len;

	count = 0;
	len = (int) ft_strlen(nb);
	if (!sign)
	{
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	else
	{	
		ft_addreturn(&count, ft_putchars(sign));
		ft_addreturn(&count, ft_putcharn('0', flag.width - len - 1));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	return (count);
}

char	ft_handle_sign(t_flag flag, long *n)
{
	char	sign;

	if (*n < 0)
	{
		*n = *n * -1;
		sign = '-';
	}
	else if (flag.plus == 1)
		sign = '+';
	else if (flag.space == 1)
		sign = ' ';
	else
		sign = 0;
	return (sign);
}

int	ft_print_nb(t_flag flag, int nbr)
{
	char	*nb;
	long	n;
	int		count;
	char	sign;

	n = (long) nbr;
	sign = ft_handle_sign(flag, &n);
	count = 0;
	nb = ft_ltoa_base(n, "0123456789");
	if (!nb)
		return (-1);	
	if (nbr == 0 && flag.prec == 0)
		nb[0] = '\0';
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_nb1(flag, nb, sign));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_nb2(flag, nb, sign));
	else
		ft_addreturn(&count, ft_print_nb1_1(flag, nb, sign));
	free(nb);
	return (count);
}