/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:47:31 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/24 18:15:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static void	init_ij(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*cs1;
	char	*cs2;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	cs1 = (char *) s1;
	cs2 = (char *) s2;
	init_ij(&i, &j);
	s = ft_calloc(ft_strlen(cs1) + ft_strlen(cs2) + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (i < ft_strlen(cs1))
	{
		s[i] = cs1[i];
		i++;
	}
	while (j < ft_strlen(cs2))
	{
		s[j + i] = cs2[j];
		j++;
	}
	return (s);
}
