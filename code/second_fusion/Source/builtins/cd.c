/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:19 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/24 18:57:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

int	exec_cd(t_execute *exe, t_all_struct **all)
{
	char	*chemin;
	char	*tmp;
	char	*tmp2;

	if (exe->arg == NULL)
		chemin = get_value((*all)->all_va, "HOME", (*all)->status);
	else
		chemin = ft_strdup(exe->arg[0]);
	if (!chemin)
		return (print_fd("Minishell error: cd: HOME not set\n", 2), 1);
	if (chemin[0] != '\0' && chdir(chemin))
	{
		print_fd("Minishell error: cd: chemin non existant OU non les droits\n", 2);
		return (free(chemin), chemin = NULL, 1);
	}
	tmp2 = get_value((*all)->all_va, "PWD", (*all)->status);
	change_or_add_va(&((*all)->all_va), "OLDPWD", tmp2);
	tmp = getcwd(NULL, 0);
	change_or_add_va(&((*all)->all_va), "PWD", tmp);
	return (free_2str(&tmp, &tmp2), free(chemin), chemin = NULL, 0);
}
