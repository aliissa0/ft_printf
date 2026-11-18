/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:49:04 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/14 23:34:15 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*sr;

	des = dest;
	sr = src;
	if (des > sr)
	{
		while (n > 0)
		{
			n--;
			des[n] = sr[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
