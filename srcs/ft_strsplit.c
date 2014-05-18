/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:10:10 by gleger            #+#    #+#             */
/*   Updated: 2014/05/18 14:41:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				count_words(const char *str, char c)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

char			*ft_strndup(const char *src, int n)
{
	size_t		i;
	char		*res;

	if (!src)
		return (0);
	if ((res = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	res[n] = 0;
	i = n - 1;
	while (i)
	{
		res[i] = src[i];
		i--;
	}
	res[0] = src[0];
	return (res);
}

size_t			word_len(const char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		words;
	size_t		len;
	char		**tab;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if ((tab = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	tab[words] = 0;
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		len = word_len(s + j, c);
		tab[i] = ft_strndup(s + j, len);
		i++;
		j += len;
	}
	return (tab);
}

int				ft_count_words(char *s, char c)
{
	int			i;
	int			words;

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
