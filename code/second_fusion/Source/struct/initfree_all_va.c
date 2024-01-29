/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all_va.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:01:02 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 15:50:00 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static t_env	*init_va_required(t_env *tete, int err, long long shlvl)
{
	char		*nbr_str;
	char		*str;

	if (key_exist(tete, "OLDPWD") == FALSE)
		change_or_add_va(&tete, "OLDPWD", NULL, 1);
	if (key_exist(tete, "PWD") == FALSE)
		change_or_add_va(&tete, "PWD", getcwd(NULL, 0), 1);
	if (key_exist(tete, "SHLVL") == FALSE)
		change_or_add_va(&tete, "SHLVL", "1", 1);
	else
	{
		str = get_value(tete, "SHLVL", 0);
		shlvl = is_numeric2(str, 0, &err);
		free_2str(&str, NULL);
		if (shlvl >= 999)
			print_fd("minishell: warning shell leve too high, reset at 1\n", 2);
		if (shlvl >= 999 || err)
			change_or_add_va(&tete, "SHLVL", "1", 1);
		else if (shlvl < 0)
			change_or_add_va(&tete, "SHLVL", "0", 1);
		else
		{
			nbr_str = int_to_str((int)(shlvl + 1));
			change_or_add_va(&tete, "SHLVL", nbr_str, 1);
			free(nbr_str);
		}
	}
	if (key_exist(tete, "PATH") == FALSE)
		change_or_add_va(&tete, "PATH", "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", 0);
	return (change_or_add_va(&tete, "_", "minishell", 0), tete);
}

static void	add_key_value(t_env **node, char *str)
{
	size_t	start;
	size_t	stop;

	start = 0;
	stop = 0;
	while (str[stop] != '=')
		stop++;
	(*node)->key = ft_strcut(str, start, stop);
	start = stop + 1;
	if (str[start] == '\0')
	{
		(*node)->value = NULL;
		return ;
	}
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
	add_key_value(&tete, arg[i]);
	tete->show = TRUE;
	tete->next_va = copy_env(tete->next_va, arg, ++i);
	return (tete);
}

int	init_all_va(t_env **all_va, char **arg_env)
{
	t_env	*res;

	res = NULL;
	if (arg_env)
		res = copy_env(res, arg_env, 0);
	res = init_va_required(res, 0, 0);
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
