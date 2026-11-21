/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:04:02 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 02:43:19 by aliissa          ###   ########.fr       */
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

int    ft_print_nb1(t_flag flag, char *nb, char sign)
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
	int count;
	int len;
	
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
	char 			*add;
	int				count;

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

int	ft_print_uns(t_flag flag, unsigned int	nbr)
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
