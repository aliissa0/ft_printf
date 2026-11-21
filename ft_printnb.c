/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:30:06 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/21 16:43:13 by aliissa          ###   ########.fr       */
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

int	ft_print_nb(int nbr)
{
	int		count;
	long	n;
	char	*nb;

	n = (long) nbr;
	count = 0;
	if (n < 0)
	{
		ft_addreturn(&count, ft_putchars('-'));
		n = n * -1;
	}
	nb = ft_ltoa_base(n, "0123456789");
	if (!nb)
		return (-1);
	ft_addreturn(&count, ft_print_str(nb));
	free(nb);
	return (count);
}

int	ft_print_uns(unsigned int nbr)
{
	char	*nb;
	int		count;

	count = 0;
	nb = ft_ltoa_base(nbr, "0123456789");
	if (!nb)
		return (-1);
	ft_addreturn(&count, ft_print_str(nb));
	free(nb);
	return (count);
}
