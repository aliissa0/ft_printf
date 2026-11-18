/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:58:48 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/18 18:39:33 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countdigit(long nb, int leng)
{
	int	count;

	count = 1;
	while (nb >= leng)
	{
		count++;
		nb = nb / leng;
	}
	return (count);
}

void	ft_putnbr_base(long nbr, char *base, char *res, int *i)
{
	long	ba;

	ba = (long) ft_strlen(base);
	if (nbr >= ba)
		ft_putnbr_base(nbr / ba, base, res, i);
	res[*i] = base[nbr % ba];
	*i = *i + 1;
}

char	*ft_ltoa_base(long nb, char *base_to)
{
	int			i;
	char		*res;

	res = malloc(ft_countdigit(nb, ft_strlen(base_to)));
	if (res == NULL)
		return (NULL);
	i = 0;
	ft_putnbr_base(nb, base_to, res, &i);
	return (res);
}

