/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_walls_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:01:34 by gleger            #+#    #+#             */
/*   Updated: 2014/05/14 03:03:14 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

void	set_rays(t_wolf *ptr, int x)
{
	double		colpos;

	colpos = 2 * x / (double)WIDTH - 1;
	ptr->raydirx = ptr->dirx + ptr->planex * colpos;
	ptr->raydiry = ptr->diry + ptr->planey * colpos;
	ptr->mapx = (int)ptr->posx;
	ptr->mapy = (int)ptr->posy;
}

void	intersection_dist(t_wolf *ptr)
{
	ptr->d_distx = sqrt(1 + pow(ptr->raydiry, 2) / pow(ptr->raydirx, 2));
	ptr->d_disty = sqrt(1 + pow(ptr->raydirx, 2) / pow(ptr->raydiry, 2));
	if (ptr->raydirx < 0)
		ptr->side_dx = (ptr->posx - ptr->mapx) * ptr->d_distx;
	else
		ptr->side_dx = (ptr->mapx + 1.0 - ptr->posx) * ptr->d_distx;
	if (ptr->raydiry < 0)
		ptr->side_dy = (ptr->posy - ptr->mapy) * ptr->d_disty;
	else
		ptr->side_dy = (ptr->mapy + 1.0 - ptr->posy) * ptr->d_disty;
}

void	find_wall(t_wolf *ptr)
{
	int			hit;
	int			x_angle;
	int			y_angle;

	hit = 0;
	while (!hit)
	{
		if (ptr->side_dx < ptr->side_dy)
		{
			ptr->side_dx += ptr->d_distx;
			x_angle = (ptr->raydirx < 0) ? -1 : 1;
			ptr->mapx += x_angle;
			ptr->side = 0;
		}
		else
		{
			ptr->side_dy += ptr->d_disty;
			y_angle = (ptr->raydiry < 0) ? -1 : 1;
			ptr->mapy += y_angle;
			ptr->side = 1;
		}
		if (ptr->maze[ptr->mapx][ptr->mapy] > 0)
				hit = 1;
	}
	ptr->walldist = (ptr->side == 0) ? WDISTX : WDISTY;
}

void	get_wall_height(t_wolf *ptr)
{
	double		lineheight;

	lineheight = fabs((((double)HEIGTH) / ptr->walldist));
	ptr->drawstart = -(lineheight) / 2 + HEIGTH / 2;
	if (ptr->drawstart < 0)
		ptr->drawstart = 0;
	ptr->drawend = lineheight / 2 + HEIGTH / 2;
	if (ptr->drawend >= HEIGTH)
		ptr->drawend = HEIGTH - 1;
}
