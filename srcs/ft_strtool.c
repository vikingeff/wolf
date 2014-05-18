/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:10:10 by gleger            #+#    #+#             */
/*   Updated: 2014/05/18 14:41:12 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(r = malloc(sizeof(*r) * (len + 1))))
		return (NULL);
	i = 0;
	while (len)
	{
		--len;
		r[i] = s[start + i];
		++i;
	}
	r[i] = 0;
	return (r);
}

char		*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if ((str = (char*)malloc(sizeof(*str) * size)))
	{
		while (size)
		{
			str[size] = '\0';
			size--;
		}
		str[size] = '\0';
	}
	return (str);
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = malloc(sizeof(*r) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		r[i++] = s2[j++];
	r[i] = 0;
	return (r);
}

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	new_str = NULL;
	if (s1)
	{
		while (s1[len])
			len++;
		if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
			return (new_str);
		while (i < len)
		{
			new_str[i] = s1[i];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
