/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:43:40 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/31 14:10:08 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	thend(const char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (0);
	else
		return (1);
}

static int	size(const char *s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	if (s[i] == '\0')
		j = -1;
	else
	{
		j = ft_strlen(&s[i]) - 1;
		while (s[i + j] == '\t' || s[i + j] == '\n' || s[i + j] == ' ')
			j--;
	}
	return (j + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		c;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	c = size(s);
	str = ft_memalloc(c + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	while (thend(s, i))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (str);
}
