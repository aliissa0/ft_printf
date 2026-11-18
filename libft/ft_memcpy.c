/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:49:04 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/12 13:50:45 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*sr;
	size_t				i;

	des = dest;
	sr = src;
	i = 0;
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}
