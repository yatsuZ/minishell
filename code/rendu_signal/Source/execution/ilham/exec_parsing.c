/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:33:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/31 00:08:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

char	*get_path_var(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcpm(tmp->key, "PATH") == TRUE)
			return (tmp->value);
		tmp = tmp->next_va;
	}
	return (NULL);
}

char	**get_paths_from_environment(char *path)
{
	return (ft_split(path, ':'));
}

int	ft_strncmp(const char *s1, const char *s2, const size_t n)
{
	size_t	i;
	int		j;

	i = n;
	j = 0;
	while (i && s1[j] && s2[j])
	{
		if (s1[j] != s2[j])
			return (s1[j] - s2[j]);
		j++;
		i--;
	}
	return (0);
}
