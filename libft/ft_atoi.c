/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:03:07 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 13:42:25 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					znak;

	znak = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f' ||
		*str == '\t' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
	{
		znak = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > 9223372036854775807 && znak == 1)
		return (-1);
	if (res > 9223372036854775807 && znak == -1)
		return (0);
	return (res * znak);
}
