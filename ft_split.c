/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:23:19 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/23 13:24:45 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strmcpy(char *start, int len)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_on_fail(char **splitstrs, int i)
{
	while (--i >= 0)
		free(splitstrs[i]);
	free(splitstrs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**splitstrs;
	char	*start;

	splitstrs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitstrs)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			splitstrs[i] = ft_strmcpy(start, (s - start));
			if (!splitstrs[i])
				return (ft_free_on_fail(splitstrs, i), NULL);
			i++;
		}
	}
	splitstrs[i] = NULL;
	return (splitstrs);
}
