/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:04:02 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/20 18:13:52 by aliissa          ###   ########.fr       */
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

int	ft_print_nb1(t_flag flag, char *nb, int sign)
{
	int		count;
	int		len;
	int		tlen;
	
	count = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	if (sign == 1 || flag.plus == 1)
	{
		ft_addreturn(&count, ft_putchars(nb[0]));
		nb++;
	}
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len)));
	return (count);
}

int	ft_print_nb1_1(t_flag flag, char *nb, int sign)
{
	int		count;
	int		len;
	int		tlen;
	
	count = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	if (flag.space == 1 && sign == 0 && flag.plus == 0)
		ft_addreturn(&count, ft_putchars(' '));	
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len)));
	if (sign == 1 || flag.plus == 1)
	{
		ft_addreturn(&count, ft_putchars(nb[0]));
		nb++;
	}
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	return (count);
}

int	ft_print_nb2(t_flag flag, char *nb, int sign)
{
	int		count;
	int		len;

	count = 0;
	len = (int) ft_strlen(nb);
	if (sign == 0 && flag.plus == 0)
	{
		if (flag.space == 1)
			ft_addreturn(&count, ft_putchars(' '));	
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	else
	{	
		ft_addreturn(&count, ft_putchars(nb[0]));
		nb++;
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	return (count);
}

int	ft_print_nb(t_flag flag, int nbr)
{
	char	*nb;
	int		count;
	int		sign;

	if (nbr == 0 && flag.prec == 0)
		return (0);
	count = 0;
	sign = 0;
	nb = ft_ltoa_base(nbr, "0123456789", flag);
	if (!nb)
		return (-1);	
	if (nbr < 0)
		sign = 1;
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_nb1(flag, nb, sign));
	else if (flag.minus == 0)
		ft_addreturn(&count, ft_print_nb1_1(flag, nb, sign));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_nb2(flag, nb, sign));
	free(nb);
	return (count);
}

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

int	ft_print_add(t_flag flag, int p)
{
	char *add;
	int	count;
	int	len;

	add = ft_ltoa_base(p, "0123456789abcdef", flag);
	if (!add)
		return (-1);
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

int	ft_print_uns(t_flag flag, unsigned int	nbr)
{
	char	*nb;
	int		count;

	if (nbr == 0 && flag.prec == 0)
		return (0);
	count = 0;
	nb = ft_ltoa_base(nbr, "0123456789", flag);
	if (!nb)
		return (-1);	
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_nb1(flag, nb, 0));
	else if (flag.minus == 0)
		ft_addreturn(&count, ft_print_nb1_1(flag, nb, 0));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_nb2(flag, nb, 0));
	free(nb);
	return (count);
}

int	ft_print_hx1(t_flag flag, char *nb, int cas)
{
	int		count;
	int		len;
	int		tlen;
	
	count = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	if (flag.hash == 1)
		ft_addreturn(&count, ft_print_prefix(cas));
	ft_addreturn(&count, ft_putcharn('0', tlen));
	ft_addreturn(&count, ft_putstrs(nb, len));
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len)));
	return (count);
}

int	ft_print_hx1_1(t_flag flag, char *nb, int cas)
{
	int		count;
	int		len;
	int		tlen;
	
	count = 0;
	len = (int) ft_strlen(nb);
	tlen = 0;
	if (flag.prec != -1 && flag.prec > len)
		tlen = flag.prec - len;
	if (flag.space == 1 && flag.hash == 0)
		ft_addreturn(&count, ft_putchars(' '));	
	ft_addreturn(&count, ft_putcharn(' ', flag.width - (tlen + len)));
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
	if (flag.hash == 0)
	{
		if (flag.space == 1)
			ft_addreturn(&count, ft_putchars(' '));	
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	else
	{	
		ft_addreturn(&count, ft_print_prefix(cas));
		ft_addreturn(&count, ft_putcharn('0', flag.width - len));
		ft_addreturn(&count, ft_putstrs(nb, len));
	}
	return (count);
}

int	ft_print_hexl(t_flag flag, unsigned int nbr)
{
	char	*nb;
	int		count;
	int		cas;

	if (nbr == 0 && flag.prec == 0)
		return (0);
	count = 0;
	cas = 0;	
	nb = ft_ltoa_base(nbr, "0123456789abcdef", flag);
	if (!nb)
		return (-1);	
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_hx1(flag, nb, cas));
	else if (flag.minus == 0)
		ft_addreturn(&count, ft_print_hx1_1(flag, nb, cas));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_hx2(flag, nb, cas));
	free(nb);
	return (count);
}

int	ft_print_hexu(t_flag flag, unsigned int nbr)
{
	char	*nb;
	int		count;
	int		cas;

	if (nbr == 0 && flag.prec == 0)
		return (0);
	count = 0;
	cas = 1;
	if (flag.hash == 1)
		cas = 1;
	nb = ft_ltoa_base(nbr, "0123456789ABCDEF", flag);
	if (!nb)
		return (-1);	
	if (flag.minus == 1)
		ft_addreturn(&count, ft_print_hx1(flag, nb, cas));
	else if (flag.minus == 0)
		ft_addreturn(&count, ft_print_hx1_1(flag, nb, cas));
	else if (flag.zero == 1 && flag.prec == -1)
		ft_addreturn(&count, ft_print_hx2(flag, nb, cas));
	free(nb);
	return (count);
}