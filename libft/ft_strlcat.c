/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:35:17 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/30 15:42:00 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	str = (char*)src;
	while (*(str++))
		j++;
	str = dst;
	i = 0;
	while (*(str++))
		i++;
	if (dstsize <= i)
		return (dstsize + j);
	str = dst + i;
	while (dstsize - i - 1 && *src)
	{
		*str = *src;
		str++;
		src++;
		dstsize--;
	}
	*str = 0;
	return (i + j);
}
