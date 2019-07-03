/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:01:16 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/03 15:03:57 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, int pow)
{
	int res;

	res = num;
	if (!pow)
		return (1);
	else if (pow == 1)
		return (num);
	while (pow != 1)
	{
		res = res * num;
		pow--;
	}
	return (res);
}
