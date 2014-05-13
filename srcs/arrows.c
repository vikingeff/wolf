/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:58:41 by po-conno          #+#    #+#             */
/*   Updated: 2014/01/19 18:00:32 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf3d.h"

void	go_front(t_wolf *ptr)
{
	if (ptr->maze[(int)(ptr->posx + ptr->dirx * MSPEED)][(int)(ptr->posy)] <= 0)
		ptr->posx += ptr->dirx * MSPEED;
	if (ptr->maze[(int)(ptr->posx)][(int)(ptr->posy + ptr->diry * MSPEED)] <= 0)
		ptr->posy += ptr->diry * MSPEED;
}

void	go_back(t_wolf *ptr)
{
	if (ptr->maze[(int)(ptr->posx - ptr->dirx * MSPEED)][(int)(ptr->posy)] <= 0)
		ptr->posx -= ptr->dirx * MSPEED;
	if (ptr->maze[(int)(ptr->posx)][(int)(ptr->posy - ptr->diry * MSPEED)] <= 0)
		ptr->posy -= ptr->diry * MSPEED;
}

void	go_left(t_wolf *ptr)
{
	double		olddirx;
	double		oldplanex;

	olddirx = ptr->dirx;
	ptr->dirx = ptr->dirx * cos(-RSPEED) - ptr->diry * sin(-RSPEED);
	ptr->diry = olddirx * sin(-RSPEED) + ptr->diry * cos(-RSPEED);
	oldplanex = ptr->planex;
	ptr->planex = ptr->planex * cos(-RSPEED) - ptr->planey * sin(-RSPEED);
	ptr->planey = oldplanex * sin(-RSPEED) + ptr->planey * cos(-RSPEED);
}

void	go_right(t_wolf *ptr)
{
	double		olddirx;
	double		oldplanex;

	olddirx = ptr->dirx;
	ptr->dirx = ptr->dirx * cos(RSPEED) - ptr->diry * sin(RSPEED);
	ptr->diry = olddirx * sin(RSPEED) + ptr->diry * cos(RSPEED);
	oldplanex = ptr->planex;
	ptr->planex = ptr->planex * cos(RSPEED) - ptr->planey * sin(RSPEED);
	ptr->planey = oldplanex * sin(RSPEED) + ptr->planey * cos(RSPEED);
}
