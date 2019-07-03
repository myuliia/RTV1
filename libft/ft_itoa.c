/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:43:20 by myuliia           #+#    #+#             */
/*   Updated: 2018/10/31 14:23:19 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa_n(int n)
{
	char	*str;
	int		l;

	l = ft_count_number(n);
	str = ft_memalloc(l + 2);
	if (!str)
		return (NULL);
	n = -n;
	while (l > 0)
	{
		str[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	str[0] = '-';
	return (str);
}

static char		*itoa_p(int p)
{
	char	*str;
	int		l;

	l = ft_count_number(p);
	str = ft_memalloc(l + 1);
	if (!str)
		return (NULL);
	while (l-- > 0)
	{
		str[l] = (p % 10) + '0';
		p = p / 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char *str;

	if (n == -2147483648)
	{
		str = ft_memalloc(11);
		if (!str)
			return (NULL);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (n == 0)
	{
		str = ft_memalloc(2);
		if (!str)
			return (NULL);
		ft_strcpy(str, "0");
		return (str);
	}
	if (n > 0)
		return (itoa_p(n));
	else
		return (itoa_n(n));
}
