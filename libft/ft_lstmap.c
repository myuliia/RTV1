/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:31:25 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 14:21:09 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*str;
	t_list	*s1;

	if (!lst || !f)
		return (NULL);
	if (!(str = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	str = f(lst);
	s1 = str;
	while (lst->next != NULL)
	{
		s1->next = f(lst->next);
		s1 = s1->next;
		lst = lst->next;
	}
	return (str);
}
