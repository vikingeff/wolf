/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:55:08 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 18:59:32 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "wolf3d.h"

static int		*ew_sides_colors(t_wolf *ptr)
{
	int		*color;

	color = (int *)malloc(sizeof(int) * 4);
	if (ptr->raydirx < 0)
	{
		color[0] = 0xff;
		color[1] = 0x00;
		color[2] = 0x00;
		color[3] = 0x00;
	}
	else if (ptr->raydirx > 0)
	{
		color[0] = 0xFF;
		color[1] = 0x00;
		color[2] = 0xff;
		color[3] = 0x00;
	}
	return (color);
}

static int		*ns_sides_colors(t_wolf *ptr)
{
	int		*color;

	color = (int *)malloc(sizeof(int) * 4);
	if (ptr->raydiry < 0)
	{
		color[0] = 0x00;
		color[1] = 0x00;
		color[2] = 0xff;
		color[3] = 0x00;
	}
	else if (ptr->raydiry > 0)
	{
		color[0] = 0x00;
		color[1] = 0xff;
		color[2] = 0x00;
		color[3] = 0x00;
	}
	return (color);
}

static void		draw_lines(int x, t_wolf *ptr)
{
	int		*color;
	int		addr;
	t_img	i;

	i = ptr->i;
	if (!ptr->side)
		color = ew_sides_colors(ptr);
	else
		color = ns_sides_colors(ptr);
	while (ptr->drawstart < ptr->drawend)
	{
		addr = (ptr->drawstart * i.sizel + x * (i.bpp / 8));
		i.data[addr + 0] = color[0];
		i.data[addr + 1] = color[1];
		i.data[addr + 2] = color[2];
		i.data[addr + 3] = color[3];
		++ptr->drawstart;
	}
	free(color);
}

void			draw_walls(t_wolf *ptr)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		set_rays(ptr, x);
		intersection_dist(ptr);
		find_wall(ptr);
		get_wall_height(ptr);
		draw_lines(x, ptr);
		x++;
	}
}
