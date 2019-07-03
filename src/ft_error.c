/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:09:17 by myuliia           #+#    #+#             */
/*   Updated: 2019/06/05 14:18:10 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	ft_error(int n)
{
	if (n == 0)
		ft_putstr("Error\n");
	if (n == 1)
		ft_putstr("Usage: ./RTv1 scene\n");
	if (n == 2)
		ft_putstr("File doesn't open\n");
	if (n == 3)
		ft_putstr("Name of file should start from word scene\n");
	exit(0);
}

int		destroy(void)
{
	system("killall afplay");
	exit(0);
}
