/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:57:48 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/30 15:27:18 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (d < s)
	{
		while (len)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}
	}
	else
		while (len)
		{
			*(d + len - 1) = *(s + len - 1);
			len--;
		}
	return (dst);
}
