/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:04:02 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/18 18:45:13 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pad(int padd , char *str, char c)
{
	char	*p;
	size_t	size;

	size = padd - ft_strlen(str);
	p = malloc((size + 1) * sizeof(char));
	// if (!p)
	// 	return (NULL);
	ft_memset(p, (int)c, size);
	return (p);
}

char	*ft_prec(t_flag flag, char *str)
{
	if (flag.prec > 0 && flag.prec < (int)ft_strlen(str))
		str = ft_substr(str, 0, flag.prec);
	return (str);
}

char	*ft_padding(t_flag flag, char *str, char c)
{
	char	*pd;

	if (flag.width >= ft_strlen(str))
		pd = ft_pad(flag.width, str, c);
	if (flag.width < ft_strlen(str))
		return (NULL);
	if (flag.minus == 1)
		return (ft_strjoin(str, pd));
	return (ft_strjoin(pd, str));
}

void	ft_print_char(t_flag flag, int c)
{
	char 	*init;
	char	*out;
	int		width;
	size_t	count;

	count = 0;
	width = flag.width;
	init = malloc(2 * sizeof(char));
	// if (!init)
	// 	return (NULL);
	init[0] = (char )c;
	init[1] = '\0';
	if (width > 1)
	{
		out = ft_padding(flag, init, ' ');
		// if (!out)
		// 	return (NULL);
		ft_putstr_fd(out, 1);
		free(out);
		return ;
	}
	ft_putstr_fd(init, 1);
	free(init);
}

void	ft_print_str(t_flag flag, char *str)
{
	size_t		width;
	int			count;
	char		*output;

	width = flag.width;
	count = 0;
	output = NULL;
	str = ft_prec(flag, str);
	output = ft_padding(flag, str, ' ');
	if (!output)
	{
		ft_putstr_fd(str, 1);
		return ;
	}
	ft_putstr_fd(output, 1);
	free(output);
	return ;
}

char	*ft_precint(t_flag flag, char *str, int	neg)
{
	char	*pd;
	char	*res;

	if (flag.prec > (int)ft_strlen(str))
		pd = ft_pad(flag.prec, str, '0');
	res = ft_strjoin(pd, str);
	if (flag.plus == 1 && neg == 0)
		res = ft_strjoin("+", res);
	else if(neg == 1)
		res = ft_strjoin("-", res);
	if (flag.width >= ft_strlen(res))
		pd = ft_pad(flag.width, res, ' ');
	if (flag.minus == 1)
		res = ft_strjoin(res, pd);
	else
		res = ft_strjoin(pd, res);
	return (res);
	
}

void	ft_print_nb(t_flag flag, int nbr)
{
	char	*res;
	long	nb;
	int		neg;

	nb = (long)nbr;
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	res = ft_ltoa_base(nb, "0123456789");
	// if (!res)
	// 	return (NULL);
	res = ft_precint(flag, res, neg);
	ft_putstr_fd(res, 1);
}
