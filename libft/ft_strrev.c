/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:57:43 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 18:33:35 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (j > i)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i++;
		j--;
	}
	return (s);
}
