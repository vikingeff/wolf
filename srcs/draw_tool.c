/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:58:27 by gleger            #+#    #+#             */
/*   Updated: 2014/05/18 15:26:38 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>

int		set_cam(t_wolf *ptr, int max_w, int max_h)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < max_h)
	{
		x = 0;
		while (x < max_w)
		{
			if (ptr->maze[y][x] == -1)
			{
				ptr->posy = y + 0.5;
				ptr->posx = x + 0.5;
				ptr->dirx = 0;
				ptr->diry = 1;
				ptr->planex = ptr->diry * -0.66;
				ptr->planey = ptr->dirx * -0.66;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void	make_blank(t_wolf *ptr)
{
	int		addr;
	int		x;
	int		y;
	t_img	i;

	x = 0;
	i = ptr->i;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			addr = (y * i.sizel + x * (i.bpp / 8));
			i.data[addr + 0] = 0x00;
			i.data[addr + 1] = 0x00;
			i.data[addr + 2] = 0x00;
			i.data[addr + 3] = 0x00;
			++y;
		}
		++x;
	}
}

void	draw_sky(t_wolf *ptr)
{
	int		x;
	int		y;
	int		addr;
	t_img	i;

	x = 0;
	i = ptr->i;
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
	t_img	i;

	i = ptr->i;
	x = 0;
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
