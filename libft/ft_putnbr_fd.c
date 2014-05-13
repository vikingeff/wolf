/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:16:04 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 19:17:36 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		i = n / 10;
		ft_putnbr_fd(i, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
	else
		ft_putchar_fd('0' + n, fd);
}
