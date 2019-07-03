/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:46:30 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/02 11:09:08 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	if (content == NULL)
	{
		str->content = NULL;
		str->content_size = 0;
		str->next = NULL;
	}
	else
	{
		str->content = malloc(content_size);
		if (str->content == NULL)
		{
			free(str);
			return (NULL);
		}
		ft_memcpy(str->content, content, content_size);
		str->content_size = content_size;
		str->next = NULL;
	}
	return (str);
}
