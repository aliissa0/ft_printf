/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:36:21 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/15 16:02:14 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;
	char			*p;

	i = 0;
	p = 0;
	str = (char *) s;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			p = str + i;
		i++;
	}
	if (str[i] == (unsigned char) c)
		return (str + i);
	return (p);
}
