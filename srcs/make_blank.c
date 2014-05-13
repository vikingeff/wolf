/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_blank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 22:35:28 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 02:59:23 by po-conno         ###   ########.fr       */
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
