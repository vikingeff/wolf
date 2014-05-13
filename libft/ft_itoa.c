/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:09:23 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/29 21:06:57 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_fill(int n, char *s, int neg)
{
	int		i;

	i = 0;
	while (n >= 10)
	{
		s[i++] = '0' + n % 10;
		n /= 10;
	}
	s[i] = '0' + n;
	if (neg == 1)
		s[i + 1] = '-';
	return (s);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*s;
	int		neg;

	i = 0;
	neg = (n < 0) ? 1 : 0;
	if (neg)
	{
		if (n == -2147483648)
		{
			s = ft_strnew(11);
			if (s == 0)
				return (0);
			return (s = ft_strcpy(s, "-2147483648"));
		}
		n *= -1;
	}
	s = ft_strnew(ft_count(n) + neg);
	if (s == 0)
		return (0);
	ft_fill(n, s, neg);
	return (ft_strrev(s));
}
