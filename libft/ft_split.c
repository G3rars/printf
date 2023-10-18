/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:52:57 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/15 14:52:59 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_wordlen(const char *s, int *i, int *word_len, char c)
{
	while (s[*i] != '\0' && s[*i] != c)
	{
		(*word_len)++;
		(*i)++;
	}
}

static int	ft_wordcount(const char *s, char c)
{
	int	trigger;
	int	i;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static void	*ft_copy(const char *s, int len, char **res, int z)
{
	res[z] = (char *)malloc(len + 1);
	if (res[z] == NULL)
	{
		while (z > 0)
		{
			free(res[z - 1]);
			z--;
		}
		free(res);
		return (NULL);
	}
	ft_strlcpy(res[z], s, len + 1);
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		word_len;
	int		i;
	int		z;
	char	**res;

	i = 0;
	z = 0;
	res = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		word_len = 0;
		ft_wordlen(s, &i, &word_len, c);
		if (word_len > 0)
		{
			if (!(ft_copy(&s[i - word_len], word_len, res, z)))
				return (NULL);
			z++;
		}
		else
			i++;
	}
	res[z] = (NULL);
	return (res);
}
