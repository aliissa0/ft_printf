/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:32:57 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/15 16:08:08 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest;

	j = 0;
	dest = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest < size && dst[dest])
		dest++;
	if (size <= dest)
		return (ft_strlen(src) + size);
	i = dest;
	while ((src[j] != '\0') && (i < (size - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest + ft_strlen(src));
}
