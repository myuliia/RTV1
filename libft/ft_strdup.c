/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:53:34 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/26 18:51:57 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		i;

	i = 0;
	if (!(d = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	if (d)
	{
		while (s1[i] != '\0')
		{
			d[i] = s1[i];
			i++;
		}
	}
	d[i] = '\0';
	return (d);
}
