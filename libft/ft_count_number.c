/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:20:42 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/03 13:53:57 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_number(int n)
{
	int i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}