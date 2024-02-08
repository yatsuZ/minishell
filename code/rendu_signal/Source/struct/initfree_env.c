/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:57:52 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/04 14:30:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	free_tab(char ***tableau)
{
	size_t	i;

	i = 0;
	if (!tableau || !(*tableau))
		return ;
	while ((*tableau)[i])
	{
		free((*tableau)[i]);
		(*tableau)[i] = NULL;
		i++;
	}
	free((*tableau));
	(*tableau) = NULL;
}

void	free_env(t_env **env)
{
	if (!env)
		return ;
	free_2str(&((*env)->key), &((*env)->value));
	(*env)->next_va = NULL;
	free(*env);
	(*env) = NULL;
}

static char	**creat_env(size_t nbr_of_env, t_env *all_va)
{
	char	*str;
	char	**res;
	size_t	i;

	i = 0;
	res = NULL;
	if (nbr_of_env)
		res = ft_calloc(nbr_of_env + 1, sizeof(char **));
	while (all_va)
	{
		str = NULL;
		if (all_va->show && all_va->value)
		{
			str_add(&str, all_va->key, 0);
			str_add(&str, "=", 0);
			str_add(&str, all_va->value, 0);
			res[i++] = ft_strdup(str);
			free_2str(&str, NULL);
		}
		all_va = all_va->next_va;
	}
	return (res);
}

void	update_env(t_all_struct **all)
{
	size_t	nbr_of_va;
	t_env	*all_va;

	if (!all || !(*all))
		return ;
	if ((*all)->env)
		free_tab(&((*all)->env));
	all_va = (*all)->all_va;
	nbr_of_va = 0;
	while (all_va)
	{
		if (all_va->show && all_va->value)
			nbr_of_va++;
		all_va = all_va->next_va;
	}
	(*all)->env = creat_env(nbr_of_va, (*all)->all_va);
}
