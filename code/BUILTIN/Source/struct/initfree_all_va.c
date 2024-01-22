/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:02 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 10:55:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static void	get_key_value(t_env **node, char *str)
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
	(*node)->value = ft_strcut(str, start, stop);
}

static t_env	*copy_env(t_env *tete, char **arg, size_t i)
{
	if (arg[i] == NULL)
		return (NULL);
	tete = ft_calloc(1, sizeof(t_env));
	if (!tete)
		return (NULL);
	get_key_value(&tete, arg[i]);
	tete->next_va = copy_env(tete->next_va, arg, ++i);
	return (tete);
}

int	init_all_va(t_env **all_va, char **arg_env)
{
	t_env	*res;

	res = NULL;
	if (!(!arg_env || !arg_env[0]))
		res = copy_env(res, arg_env, 0);
	return ((*all_va) = res, 0);
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
