/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:09:44 by myuliia           #+#    #+#             */
/*   Updated: 2019/01/13 16:14:43 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)ft_strnew(a + b)))
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	while (s2[b])
		str[a++] = s2[b++];
	str[a] = '\0';
	free(s1);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[100];
	char		*tmp;
	int			n;
	char		buf[BUFF_SIZE + 1];

	n = 0;
	IF_NO(fd < 0 || BUFF_SIZE < 1 || BUFF_SIZE >= 8000000 ||
		(n = read(fd, buf, BUFF_SIZE)) == -1);
	str[fd] = str[fd] ? str[fd] : ft_strdup("");
	tmp = str[fd];
	buf[n] = '\0';
	str[fd] = ft_free_strjoin(str[fd], buf);
	tmp = str[fd];
	if (!strlen(str[fd]))
		return (0);
	else if (ft_strchr(str[fd], '\n') &&
			(*line = ft_strsub(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd])))
		str[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	else if (!n && ft_strlen(str[fd]) && (*line = ft_strdup(str[fd])))
		str[fd] = 0;
	else
		return (get_next_line(fd, line));
	free(tmp);
	return (1);
}
