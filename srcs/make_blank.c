/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_blank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 22:35:28 by gleger            #+#    #+#             */
/*   Updated: 2014/05/14 03:03:29 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "wolf3d.h"

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
