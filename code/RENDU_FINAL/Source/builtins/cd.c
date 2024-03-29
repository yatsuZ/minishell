/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 22:30:16 by yzaoui           ###   ########.fr       */
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

char	*get_first_arg_no_null(char **arv, size_t arc, size_t i)
{
	while (i < arc)
	{
		if (arv[i] != NULL)
			return (ft_strdup(arv[i]));
		i++;
	}
	return (NULL);
}

static int	exec_cd2(char *chemin, t_all_struct **all)
{
	char		*tmp;
	char		*tmp2;
	t_boolean	show;

	tmp2 = get_value((*all)->all_va, "PWD", (*all)->status);
	show = i_can_show_va((*all)->all_va, "OLDPWD");
	if (key_exist((*all)->all_va, "PWD"))
		change_or_add_va(&((*all)->all_va), "OLDPWD", tmp2, show);
	tmp = getcwd(NULL, 0);
	show = i_can_show_va((*all)->all_va, "PWD");
	change_or_add_va(&((*all)->all_va), "PWD", tmp, show);
	return (free_2str(&tmp, &tmp2), free(chemin), chemin = NULL, 0);
}

int	exec_cd(t_execute *exe, t_all_struct **all)
{
	char		*chemin;

	if (exe->argc > 2)
		return (print_fd("Minishell error: cd: too many arguments\n", 2), 1);
	chemin = get_first_arg_no_null(exe->arg, exe->argc, 1);
	if (!chemin)
		chemin = get_value((*all)->all_va, "HOME", (*all)->status);
	if (!chemin)
		return (print_fd("Minishell error: cd: HOME not set\n", 2), 1);
	if (chemin[0] != '\0' && chdir(chemin))
		return (print_fd("Minishell error: cd: \
chemin non existant OU non les droits\n", 2), free(chemin), chemin = NULL, 1);
	return (exec_cd2(chemin, all));
}
