/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/27 01:13:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_boolean	i_can_show_va(t_env *env, char *str)
{
	while (env && str)
	{
		if (ft_strcpm(env->key, str))
			return (env->show);
		env = env->next_va;
	}
	return (FALSE);
}

t_boolean	key_exist(t_env *env, char *str)
{
	while (env)
	{
		if (ft_strcpm(env->key, str))
			return (TRUE);
		env = env->next_va;
	}
	return (FALSE);
}

int	exec_cd(t_execute *exe, t_all_struct **all)
{
	char		*chemin;
	char		*tmp;
	char		*tmp2;
	t_boolean	show;

	if (exe->nbr_arg == 0)
		chemin = get_value((*all)->all_va, "HOME", (*all)->status);
	else
		chemin = ft_strdup(exe->arg[0]);
	if (!chemin)
		return (print_fd("Minishell error: cd: HOME not set\n", 2), 1);
	if (chemin[0] != '\0' && chdir(chemin))
		return (print_fd("Minishell error: cd: \
chemin non existant OU non les droits\n", 2), free(chemin), chemin = NULL, 1);
	tmp2 = get_value((*all)->all_va, "PWD", (*all)->status);
	show = i_can_show_va((*all)->all_va, "OLDPWD");
	if (key_exist((*all)->all_va, "PWD"))
		change_or_add_va(&((*all)->all_va), "OLDPWD", tmp2, show);
	tmp = getcwd(NULL, 0);
	show = i_can_show_va((*all)->all_va, "PWD");
	change_or_add_va(&((*all)->all_va), "PWD", tmp, show);
	return (free_2str(&tmp, &tmp2), free(chemin), chemin = NULL, 0);
}
