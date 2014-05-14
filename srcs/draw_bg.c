/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:30:33 by gleger            #+#    #+#             */
/*   Updated: 2014/05/14 03:02:40 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

void	draw_sky(t_wolf *ptr)
{
	int		x;
	int		y;
	int		addr;
	int		color;
	t_img	i;

	x = 0;
	i = ptr->i;
	color = 0x007FFF;
	while (x < WIDTH)
	{
		y = 0;
		while (y < (HEIGTH / 2))
		{
			addr = (y * i.sizel + x * (i.bpp / 8));
			i.data[addr + 0] = 0xf0;
			i.data[addr + 1] = 0xde;
			i.data[addr + 2] = 0xb4;
			i.data[addr + 3] = 0x00;
			y++;
		}
		x++;
	}
}

void	draw_floor(t_wolf *ptr)
{
	int		x;
	int		y;
	int		addr;
	int		color;
	t_img	i;

	i = ptr->i;
	x = 0;
	color = 0xFF0000;
	while (x < WIDTH)
	{
		y = (HEIGTH / 2);
		while (y < HEIGTH)
		{
			addr = (y * i.sizel + x * (i.bpp / 8));
			i.data[addr + 0] = 0x65;
			i.data[addr + 1] = 0x5c;
			i.data[addr + 2] = 0x5a;
			i.data[addr + 3] = 0x00;
			y++;
		}
		x++;
	}
}

void	draw_bg(t_wolf *ptr)
{
	draw_sky(ptr);
	draw_floor(ptr);
}
