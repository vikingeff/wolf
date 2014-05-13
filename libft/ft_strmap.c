/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:06:22 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 18:45:58 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = ft_memalloc(ft_strlen(s));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
