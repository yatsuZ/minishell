/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:02 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 21:18:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static t_env	*copy_env(t_env *tete, char **arg, size_t i, int *err)
{
	size_t	start;
	size_t	stop;

	if (arg[i] == NULL || *err > 0)
		return (NULL);
	else if (arg[i] == NULL)
	{
		if (*err == -1)
		{
			tete = ft_calloc(1, sizeof(t_env));
			if (!tete)
				return (*err = 1, NULL);
			tete->key = ft_strdup("PWD");
			tete->value = getcwd(0, 0);
			tete->next_va = NULL;
			return (tete);
		}
	}
	tete = ft_calloc(1, sizeof(t_env));
	if (!tete)
		return (*err = 1, NULL);
	start = 0;
	stop = 0;
	while (arg[i][stop] != '=')
		stop++;
	tete->key = ft_strcut(arg[i], start, stop);
	start = stop + 1;
	while (arg[i][stop])
		stop++;
	if (ft_strcpm(tete->key, "PWD"))
	{
		*err = 0;
		tete->value = ft_strcut(arg[i], start, stop);
	}
	else
		tete->value = ft_strcut(arg[i], start, stop);
	tete->next_va = copy_env(tete->next_va, arg, ++i, err);
	return (tete);
}

int	init_all_va(t_env **all_va, char **arg_env)
{
	t_env	*res;
	int		err;

	err = -1;
	if (!arg_env || !arg_env[0])
	{
		res = ft_calloc(1, sizeof(t_env));
		if (!res)
			return ((*all_va) = res, 1);
		res->key = ft_strdup("PWD");
		res->value = getcwd(0, 0);
		res->next_va = NULL;
	}
	else
	{
		res = NULL;
		res = copy_env(res, arg_env, 0, &err);
	}
	return ((*all_va) = res, err);
}

void	free_all_va(t_env *all_va)
{
	if (!all_va)
		return ;
	free(all_va->key);
	free(all_va->value);
	all_va->key = NULL;
	all_va->value = NULL;
	free_all_va(all_va->next_va);
	all_va->next_va = NULL;
	free(all_va);
	all_va = NULL;
}