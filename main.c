/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:42:33 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 19:05:33 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X.h>
#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"

t_wolf	*init_ptr(void)
{
	static t_wolf	*ptr = NULL;

	if (ptr)
		return (ptr);
	ptr = (t_wolf *)malloc(sizeof(t_wolf));
	return (ptr);
}

t_mlx	*init_mlx(t_mlx *e)
{
	e = (t_mlx *)malloc(sizeof(t_mlx));
	return (e);
}

int		main(int argc, char **argv)
{
	t_wolf		*ptr;
	t_lst		*list;
	t_mlx		*e;

	if (argc > 1)
		return (-1);
	(void)argv;
	e = NULL;
	ptr = init_ptr();
	ptr->maze = read_maze("maze.w3d", ptr->maze, &list);
	if (set_cam(ptr, list->width, list->heigth))
		return (-1);
	free_list(list);
	e = init_mlx(e);
	set_mlx(ptr, e);
	create_image(ptr);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_hook(e->win, KeyPress, KeyPressMask, &key_hook, ptr);
	mlx_hook(e->win, KeyRelease, KeyReleaseMask, &key_release, ptr);
	mlx_loop_hook(e->mlx, &expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
