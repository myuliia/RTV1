/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:06:08 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 13:41:15 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*nd;
	size_t	i;
	size_t	j;

	hay = (char *)haystack;
	nd = (char *)needle;
	i = 0;
	if (needle[0] == '\0')
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] == nd[j] && (i + j) < len)
		{
			j++;
			if (nd[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
