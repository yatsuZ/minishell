/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:36:24 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 17:55:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lon;
	char	*news;
	size_t	space;

	if (!s)
		return (NULL);
	lon = ft_strlen((char *) s);
	if (start > lon)
		return (ft_strdup(""));
	space = lon - start ;
	if (space > len)
		space = len;
	news = ft_calloc(space + 1, sizeof(char));
	i = 0;
	while (news && s[i + start] && i < len)
	{
		news[i] = s[i + start];
		i++;
	}
	if (news && news[i])
		news[i] = '\0';
	return (news);
}

static size_t	ft_nomber_of_word(const char *s, char c)
{
	size_t	nbw;
	size_t	i;
	int		boolean;

	boolean = 1;
	i = 0;
	nbw = 0;
	while (s[i])
	{
		if (s[i] == c)
			boolean = 1;
		else
		{
			if (boolean)
				nbw++;
			boolean = 0;
		}
		i++;
	}
	return (nbw);
}

static char	**ft_cutsplit(size_t i, size_t nbw, const char *s, char c)
{
	size_t	j;
	char	**tableau;

	tableau = ft_calloc(nbw, sizeof(char *));
	j = 1;
	nbw = 0;
	while (s[i] && tableau)
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				while (s[i] && s[i] != c)
					i++;
				tableau[nbw] = ft_substr(s, j, i-- - j);
				nbw++;
			}
			j = 0;
		}
		i++;
	}
	return (tableau);
}

static int	ft_secure(size_t j, const char *s, char c, size_t i)
{
	char	*sec;

	while (s[i])
	{
		if (s[i] == c)
			j = 1;
		else
		{
			if (j)
			{
				j = i;
				while (s[i] && s[i] != 0)
					i++;
				sec = ft_substr(s, j, i-- - j);
				if (!sec)
					return (0);
				free(sec);
			}
			j = 0;
		}
		i++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	nbw;
	char	**tableau;

	if (!s)
		return (NULL);
	nbw = ft_nomber_of_word(s, c);
	if (ft_secure(1, s, c, 0) == 0)
		return (NULL);
	tableau = ft_cutsplit(0, 1 + nbw, s, c);
	if (!tableau)
		return (NULL);
	tableau[nbw] = NULL;
	return (tableau);
}