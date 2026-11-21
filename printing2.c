/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:58:48 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 02:15:52 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countdigit(unsigned long nb, unsigned long leng)
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

void	ft_putnbr_base(unsigned long nbr, char *base, char *res, int *i)
{
	unsigned long	ba;

	ba = (unsigned long) ft_strlen(base);
	if (nbr >= ba)
		ft_putnbr_base(nbr / ba, base, res, i);
	res[*i] = base[nbr % ba];
	*i = *i + 1;
}

char	*ft_ltoa_base(unsigned long nb, char *base_to)
{
	int		i;
	char	*res;

	res = malloc((ft_countdigit(nb, ft_strlen(base_to)) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	ft_putnbr_base(nb, base_to, res, &i);
	res[i] = '\0';
	return (res);
}
