/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 13:58:27 by gleger            #+#    #+#             */
/*   Updated: 2014/05/14 03:03:45 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "wolf3d.h"

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
