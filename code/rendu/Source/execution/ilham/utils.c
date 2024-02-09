/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:09:15 by ilouacha          #+#    #+#             */
/*   Updated: 2024/02/09 00:30:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len, int *err)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*z;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if ((start > len_s) || (len_s == 0))
		return (ft_strdup("", err));
	i = 0;
	while ((i < len) && (i < (len_s - start)))
		i++;
	z = ft_calloc((i + 1), sizeof(char *));
	if (!z)
		return (*err = 1, NULL);
	i = 0;
	while ((i < len) && (i < (len_s - start)))
	{
		z[i] = s[start + i];
		i++;
	}
	z[i] = '\0';
	return (z);
}

static unsigned int	count_word(char const *s, char c)
{
	int				i;
	unsigned int	nbr_word;
	int				start_word;

	nbr_word = 0;
	i = -1;
	start_word = 0;
	while (s[++i])
	{
		if (s[i] != c && start_word == 0)
		{
			start_word = 1;
			nbr_word++;
		}
		else if (s[i] == c)
			start_word = 0;
	}
	return (nbr_word);
}

static char	**free_all_split(char **array, int k)
{
	int	i;

	i = -1;
	while (++i <= k)
		free(array[i]);
	free(array);
	return (NULL);
}

static char	**ft_under_split(char const *s, char c, char **splitted, int *err)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (++i <= (int)ft_strlen(s))
	{
		if ((s[i] != c) && (j < 0))
		{
			j = i;
		}
		else if (((s[i] == c) || (s[i] == '\0')) && (j >= 0))
		{
			splitted[k] = ft_substr(s, j, i - j, err);
			if (*err == 0 || !splitted[k])
				return (*err = 1, free_all_split(splitted, k));
			k++;
			j = -1;
		}
	}
	splitted[k] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c, int *err)
{
	char			**splitted;

	if (!s || *err)
		return (NULL);
	splitted = ft_calloc(((count_word(s, c)) + 1), sizeof(char *));
	if (!splitted)
		return (*err = 1, NULL);
	splitted = ft_under_split(s, c, splitted, err);
	return (splitted);
}
