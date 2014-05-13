/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:56:21 by po-conno          #+#    #+#             */
/*   Updated: 2013/12/22 21:07:58 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_count_words(char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (words);
		while (s[i] != c && s[i] != '\0')
			i++;
		words++;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	int		start;
	int		len;
	int		str;
	char	**tab;

	start = 0;
	str = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(*tab) * ft_count_words((char *)s, c) + 1);
	if (!tab)
		return (NULL);
	while (s[start] != '\0')
	{
		len = 0;
		while (s[start + len] == c)
			start++;
		while (s[start + len] != c && s[start + len] != '\0')
			len++;
		if (s[start] != '\0')
			tab[str++] = ft_strsub(s, (unsigned int)start, len);
		start += len;
	}
	tab[str] = NULL;
	return (tab);
}
