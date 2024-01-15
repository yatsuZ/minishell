/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:02 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/10 22:28:12 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static void	add_key_value(t_env **node, char *str, int *err)
{
	size_t	start;
	size_t	stop;

	start = 0;
	stop = 0;
	while (str[stop] != '=')
		stop++;
	(*node)->key = ft_strcut(str, start, stop);
	start = stop + 1;
	while (str[stop])
		stop++;
	if (ft_strcpm((*node)->key, "PATH"))
	{
		*err = *err + 2;
		(*node)->value = getcwd(0, 0);
		return ;
	}
	else if (ft_strcpm((*node)->key, "PWD"))
		*err = *err + 1;
	(*node)->value = ft_strcut(str, start, stop);
}
/**
 * What is the meaning of err == -1, err <= -2 ??? 
*/
static t_env	*copy_env(t_env *tete, char **arg, size_t i, int *err)
{
	if (arg[i] == NULL || *err > 0)
		return (NULL);
	tete = ft_calloc(1, sizeof(t_env));
	if (!tete)
		return (*err = 1, NULL);
	else if (arg[i] == NULL)
	{
		if (*err <= -2)
		{
			*err = *err + 2;
			return (tete->key = ft_strdup("PATH"), tete->value = ft_strdup(""), \
			tete->next_va = copy_env(tete->next_va, arg, ++i, err), \
			tete);
		}
		else if (*err == -1)
		{
			*err = *err + 1;
			return (tete->key = ft_strdup("PWD"), tete->value = getcwd(0, 0), \
			tete->next_va = copy_env(tete->next_va, arg, ++i, err), \
			tete);
		}
	}
	add_key_value(&tete, arg[i], err);
	tete->next_va = copy_env(tete->next_va, arg, ++i, err);
	return (tete);
}

static t_env	*env_null(int *err)
{
	t_env	*res;

	res = ft_calloc(1, sizeof(t_env));
	if (!res)
		return ((*err) = 1, res);
	res->key = ft_strdup("PWD");
	res->value = getcwd(0, 0);
	printf("ICI\n");
	res->next_va = ft_calloc(1, sizeof(t_env));
	if (!res->next_va)
		return ((*err) = 1, res);
	res->next_va->key = ft_strdup("PATH");
	res->next_va->value = ft_strdup("");
	res->next_va->next_va = NULL;
	return (res);
}

int	init_all_va(t_env **all_va, char **arg_env)
{
	t_env	*res;
	int		err;

	err = -3;
	if (!arg_env || !arg_env[0])
		res = env_null(&err);
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
