/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:10:10 by gleger            #+#    #+#             */
/*   Updated: 2014/05/13 12:15:35 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

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

int		count_words(const char *str, char c)
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

char		*ft_strndup(const char *src, int n)
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

size_t	word_len(const char *str, char c)
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

char	*ft_strnew(size_t size)
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

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strcpy(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	ft_strclr(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	return (NULL);
}

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (ft_isspace(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1]))
			|| (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i - 1] == '-')
		neg++;
	while (ft_isdigit(str[i]))
	{
		if (ft_isdigit(str[i]) && neg < 3)
		{
			nb = (nb * 10) + (str[i] - '0');
			if (neg == 0)
				neg = 2;
		}
		i++;
	}
	if (neg == 1)
		nb *= -1;
	return (nb);
}

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
