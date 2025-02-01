/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:16:30 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 10:12:48 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_splits(char const *s, char c)
{
	int		count;
	int		in_split;

	count = 0;
	in_split = 0;
	while (*s)
	{
		if (*s != c && !in_split)
		{
			in_split = 1;
			count++;
		}
		else if (*s == c)
			in_split = 0;
		s++;
	}
	return (count);
}

static char	**free_split(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static int	get_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**process_splits(char const *s, char c, char **split)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = get_word_len(s, c);
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
				return (free_split(split, i));
			i++;
			s += len;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		total_splits;

	if (!s || c == 9)
		return (NULL);
	total_splits = count_splits(s, c);
	split = (char **)malloc((total_splits + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (process_splits(s, c, split));
}
