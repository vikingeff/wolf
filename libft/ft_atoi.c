/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:35:43 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 20:20:50 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int		atoi;
	int		i;
	int		neg;

	atoi = 0;
	i = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (ft_strncmp(str, "-2147483648", 11) == 0 && !ft_isdigit(str[11]))
		return (-2147483648);
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		atoi = (str[i] - '0') + (atoi * 10);
		if (atoi < 0)
			return (-1);
		i++;
	}
	atoi *= neg;
	return (atoi);
}
