/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:51:40 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/03 14:46:11 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	let(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (!s || !c)
		return (NULL);
	j = ft_count_words((char *)s, c);
	if (!(str = (char **)ft_memalloc((j + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < j)
	{
		while (*s && *s == c)
			s++;
		str[i] = ft_strsub(s, 0, let(s, c));
		if (str[i] == NULL)
		{
			free(str[i]);
			return (NULL);
		}
		i++;
		s = s + let(s, c);
	}
	str[i] = NULL;
	return (str);
}
