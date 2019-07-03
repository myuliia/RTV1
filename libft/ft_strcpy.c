/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:56:02 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/25 13:25:39 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		*(dst + counter) = *(src + counter);
		counter++;
	}
	dst[counter] = '\0';
	return (dst);
}
