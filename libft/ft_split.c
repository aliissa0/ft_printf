/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliissa <aliissa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:24:51 by aliissa           #+#    #+#             */
/*   Updated: 2026/11/15 03:53:25 by aliissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *str, char c)
{
	int	count;
	int	i;
	int	word;

	i = 0;
	word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static void	free_split(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*get_word(const char *s, int *i, char c)
{
	int		j;
	char	*str;

	j = 0;
	while (s[*i] == c && s[*i] != '\0')
		*i = *i + 1;
	while (s[*i + j] != c && s[*i + j] != '\0')
		j++;
	*i += j;
	str = ft_substr(s, *i - j, j);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	arr = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	k = 0;
	while (k < wordcount(s, c))
	{
		arr[k] = get_word(s, &i, c);
		if (!arr[k])
		{
			free_split(arr, k);
			return (NULL);
		}
		k++;
	}
	arr[k] = NULL;
	return (arr);
}
