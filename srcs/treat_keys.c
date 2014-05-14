/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 18:07:42 by gleger            #+#    #+#             */
/*   Updated: 2014/05/14 03:03:53 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf3d.h"

int		key_hook(int keycode, t_wolf *ptr)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
		ptr->keys[0] = 1;
	if (keycode == 65364)
		ptr->keys[1] = 1;
	if (keycode == 65361)
		ptr->keys[2] = 1;
	if (keycode == 65363)
		ptr->keys[3] = 1;
	return (0);
}

int		key_release(int keycode, t_wolf *ptr)
{
	if (keycode == 65362)
		ptr->keys[0] = 0;
	if (keycode == 65364)
		ptr->keys[1] = 0;
	if (keycode == 65361)
		ptr->keys[2] = 0;
	if (keycode == 65363)
		ptr->keys[3] = 0;
	return (0);
}

int		loop_arrows(t_wolf *ptr)
{
	if (ptr->keys[0] == 1)
		go_front(ptr);
	if (ptr->keys[1] == 1)
		go_back(ptr);
	if (ptr->keys[2] == 1)
		go_left(ptr);
	if (ptr->keys[3] == 1)
		go_right(ptr);
	return (0);
}
