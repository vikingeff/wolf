/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:15:21 by po-conno          #+#    #+#             */
/*   Updated: 2013/11/30 18:47:24 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t				len;
	char				*str;
	unsigned int		i;
	int					j;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len --;
	if (s[i] == '\0')
		return (0);
	str = ft_strnew(len - i);
	while (i < len)
		str[j++] = s[i++];
	str[j] = '\0';
	if (str == 0)
		return (0);
	return (str);
}
