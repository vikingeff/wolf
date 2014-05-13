/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:23:26 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 18:13:07 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "wolf3d.h"

int		expose_hook(t_mlx *e)
{
	t_wolf		*ptr;

	ptr = init_ptr();
	loop_arrows(ptr);
	create_image(ptr);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	create_image(t_wolf *ptr)
{
	make_blank(ptr);
	draw_bg(ptr);
	draw_walls(ptr);
}

void	set_mlx(t_wolf *ptr, t_mlx *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGTH, "Wolf3D");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGTH);
	ptr->i.data = mlx_get_data_addr(e->img, &BPP, &SIZEL, &ENDIAN);
}
