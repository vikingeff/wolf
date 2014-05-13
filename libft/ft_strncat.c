/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:56:30 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/22 21:59:25 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	y = 0;
	while (s1[y] != '\0')
		y++;
	while (s2[i] != '\0' && i < n)
	{
		s1[y] = s2[i];
		i++;
		y++;
	}
	s1[y] = '\0';
	return (s1);
}
