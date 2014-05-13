/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:11:58 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/03 15:08:35 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (fd < 0)
		return ;
	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
}
