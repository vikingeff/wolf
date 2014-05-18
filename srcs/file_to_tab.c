/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 21:01:26 by gleger            #+#    #+#             */
/*   Updated: 2014/05/18 14:42:59 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <wolf3d.h>

int		**make_tab(char **strings, int **tab, int j, int i)
{
	static int		k = 0;
	int				l;

	l = 0;
	if (!tab)
		tab = (int **)malloc(sizeof(int *) * i);
	tab[k] = (int *)malloc(sizeof(int) * j);
	tab[k][l] = j;
	while (strings[l] != NULL)
	{
		tab[k][l] = ft_atoi(strings[l]);
		l++;
	}
	k++;
	return (tab);
}

int		**treat_list(t_lst **list, int **tab)
{
	t_lst	*tmp;
	char	**split;

	tmp = *list;
	split = NULL;
	while (tmp->next != NULL)
	{
		split = ft_strsplit(tmp->content, ' ');
		tab = make_tab(split, tab, tmp->width, (*list)->heigth);
		tmp = tmp->next;
		free_split(&split);
	}
	split = ft_strsplit(tmp->content, ' ');
	tab = make_tab(split, tab, tmp->width, (*list)->heigth);
	free_split(&split);
	return (tab);
}

int		**read_maze(char *file, int **tab, t_lst **list)
{
	t_lst	*new;
	char	*line;
	int		fd;

	line = NULL;
	tab = NULL;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (!line)
			return (0);
		new = make_list(&line);
		*list = add_to_list(list, new);
		ft_strdel(&line);
	}
	tab = treat_list(list, tab);
	close(fd);
	return (tab);
}
