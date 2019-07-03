/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:58:48 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 13:38:28 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == n[j])
		{
			j++;
			if (n[j] == '\0')
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
