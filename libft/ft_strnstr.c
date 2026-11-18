/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:56:10 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/15 04:01:20 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	if (little[j] == '\0')
		return ((char *) big);
	while (j < len && *(big + j) != '\0')
	{
		i = 0;
		k = j;
		while ((i + j) < len && (big[k] == little[i]) && (little[i] != '\0'))
		{
			i++;
			k++;
		}
		if (little[i] == '\0')
			return ((char *)(big + j));
		j++;
	}
	return (0);
}
