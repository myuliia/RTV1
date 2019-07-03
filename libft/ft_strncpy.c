/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:56:40 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/25 14:05:11 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t counter;

	counter = 0;
	while (src[counter] != '\0' && counter < len)
	{
		*(dst + counter) = *(src + counter);
		counter++;
	}
	while (counter < len)
		dst[counter++] = '\0';
	return (dst);
}
