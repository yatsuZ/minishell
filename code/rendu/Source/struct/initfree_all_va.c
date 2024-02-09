/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:02 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 21:58:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static t_env	*init_va_required(t_env *tete, int err, long long shlvl, \
int *err_m)
{
	char	*all_path;

	if (*err_m)
		return (NULL);
	all_path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	if (!(*err_m) && key_exist(tete, "OLDPWD") == FALSE)
		*err_m = change_or_add_va(&tete, "OLDPWD", NULL, 1);
	if (!(*err_m) && key_exist(tete, "PWD") == FALSE)
		*err_m = change_or_add_va(&tete, "PWD", getcwd(NULL, 0), 1);
	if (!(*err_m) && key_exist(tete, "SHLVL") == FALSE)
		*err_m = change_or_add_va(&tete, "SHLVL", "1", 1);
	else if (!(*err_m))
		*err_m = update_shlvl(tete, err, shlvl);
	if (!(*err_m) && key_exist(tete, "PATH") == FALSE)
		*err_m = change_or_add_va(&tete, "PATH", all_path, 0);
	if (*err_m)
		return (tete);
	*err_m = change_or_add_va(&tete, "_", "minishell", 0);
	return (tete);
}

static void	add_key_value(t_env **node, char *str, int *err)
{
	size_t	start;
	size_t	stop;

	start = 0;
	stop = 0;
	while (str[stop] != '=')
		stop++;
	(*node)->key = ft_strcut(str, start, stop, err);
	if (*err)
		return ;
	start = stop + 1;
	if (str[start] == '\0')
	{
		(*node)->value = NULL;
		return ;
	}
	while (str[stop])
		stop++;
	(*node)->value = ft_strcut(str, start, stop, err);
}

static t_env	*copy_env(t_env *tete, char **arg, size_t i, int *err)
{
	if (*err || arg[i] == NULL)
		return (NULL);
	tete = ft_calloc(1, sizeof(t_env));
	if (!tete)
		return (*err = 1, NULL);
	add_key_value(&tete, arg[i], err);
	if (*err)
		return (tete);
	tete->show = TRUE;
	tete->next_va = copy_env(tete->next_va, arg, ++i, err);
	return (tete);
}

int	init_all_va(t_env **all_va, char **arg_env, int *err)
{
	t_env	*res;

	res = NULL;
	if (arg_env)
		res = copy_env(res, arg_env, 0, err);
	res = init_va_required(res, 0, 0, err);
	return ((*all_va) = res, *err);
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
