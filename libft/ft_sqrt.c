/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:07:02 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/03 15:08:45 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int num)
{
	int res;

	res = 0;
	while ((res * res) != num)
	{
		if ((res * res) > num)
			return (0);
		res++;
	}
	return (res);
}
