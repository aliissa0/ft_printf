/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 21:29:04 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/15 14:30:16 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	size_t			k;
	char			*str;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (ft_isinset(s1[i], set) && s1[i])
		i++;
	while (j > i && ft_isinset(s1[j - 1], set))
		j--;
	str = malloc((j - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while ((k + i) < j)
	{
		str[k] = s1[k + i];
		k++;
	}
	str[k] = '\0';
	return (str);
}
