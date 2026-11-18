/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:40:33 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/14 07:16:53 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long *nb)
{
	int		i;
	long	n;

	i = 0;
	if (*nb == 0)
		return (1);
	if (*nb < 0)
		*nb = *nb * -1;
	n = *nb;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char	*ft_rev(char *str, int i)
{
	int		j;
	int		f;
	char	temp;

	j = 0;
	f = i - 1;
	while (f > j)
	{
		temp = str[f];
		str[f] = str[j];
		str[j] = temp;
		f--;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		dig;
	int		i;
	long	nbr;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	nbr = (long)n;
	dig = count_digits(&nbr);
	res = malloc(dig * sizeof(char) + sign + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < dig)
	{
		res[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	if (sign == 1)
		res[i++] = '-';
	ft_rev(res, i);
	return (res);
}
