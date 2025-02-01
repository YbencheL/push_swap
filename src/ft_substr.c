/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:34:42 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/26 17:13:35 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	char			*str;
	int				i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = (int)ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len < len + start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char str[] = "hello world its me 42";
	char *res = ft_substr(str, 0, 5);
	
	printf("%s", res);
}
*/