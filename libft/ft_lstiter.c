/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:21:28 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 11:36:12 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*str;

	if (!lst || !f)
		return ;
	str = lst;
	if (lst && f)
	{
		while (str)
		{
			f(str);
			str = str->next;
		}
	}
}
