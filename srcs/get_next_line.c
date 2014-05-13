/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 16:53:14 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 13:32:16 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

int			end_line(char *str, char **line, int i)
{
	char		*tmp;
	char		*tmp2;

	tmp2 = ft_strsub(str, 0, i);
	if (!tmp2)
		return (-1);
	if (!*line)
		*line = tmp2;
	else
	{
		if ((tmp = ft_strjoin(*line, tmp2)) == NULL)
			return (-1);
		ft_strdel(line);
		*line = tmp;
		ft_strdel(&tmp2);
	}
	if (!*line)
		return (-1);
	if ((tmp = ft_strsub(str, (unsigned int)i + 1, BUFF_SIZE - i)) == NULL)
		return (-1);
	ft_strclr(str);
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (1);
}

int			fill_line(char *str, char **line)
{
	char		*tmp;

	if (!*line)
	{
		*line = ft_strdup(str);
		return (0);
	}
	if ((tmp = ft_strjoin(*line, str)) == NULL)
		return (-1);
	ft_strdel(line);
	*line = ft_strdup(tmp);
	if (!*line)
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

int			find_lf(char const *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != 0)
		++i;
	return ((str[i] == '\0') ? 0 : (i + 1));
}

int			get_next_line(int const fd, char **line)
{
	int			i;
	ssize_t		ret;
	static char	*str;
	size_t		stay;

	if ((!str && !(str = ft_strnew(BUFF_SIZE))) || line == NULL)
		return (-1);
	ret = BUFF_SIZE;
	stay = (ft_strlen(str)) ? ft_strlen(str) : 0;
	while (ret == BUFF_SIZE && BUFF_SIZE > 0)
	{
		if (ft_strchr(str, '\n') == 0 && ret == BUFF_SIZE)
			ret = read(fd, (str + stay), (BUFF_SIZE - stay)) + (ssize_t)stay;
		stay = 0;
		if (ret < BUFF_SIZE && ft_strchr(str, '\n') == 0)
			ft_strclr(str);
		if ((i = find_lf(str, '\n')))
			return (end_line(str, line, (i - 1)));
		else
			if (fill_line(str, line) == -1)
				return (-1);
	}
	ft_strdel(&str);
	return ((ret < 0) ? -1 : 0);
}
