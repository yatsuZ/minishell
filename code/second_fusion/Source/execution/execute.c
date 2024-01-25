/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:23:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/25 02:31:25 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	change_va_undescore(t_execute *exe, t_env **env)
{
	char	*new_end;
	size_t	i;

	if (!exe || ft_strcpm(exe->cmd, "exit"))
		return ;
	new_end = NULL;
	i = exe->nbr_arg;
	while (exe->arg && i && !new_end)
	{
		new_end = exe->arg[i];
		i--;
	}
	if (new_end == NULL)
		new_end = exe->cmd;
	change_or_add_va(env, "_", new_end, 0);
}

// 1 Faire une ft qui execute la commande ouverture puis fermeture des fichier
int	ft_exec(t_execute *exe, t_all_struct **all)
{
	int	status;

	status = 0;
	// Open rd
	// EXEC
	// RD
	if (find_builtin(exe->cmd) != NON_BUILTIN)
		status = exec_builtin(exe, all, find_builtin(exe->cmd));
	change_va_undescore(exe, &((*all)->all_va));
	return (status);
}

// Fiare une ft qui s'occupe des redirection

//partie importante je vais juste moccupe des builtin
int	ft_all_exec(t_execute *exe, t_all_struct **all)
{
	if (!all)
		end(NULL);
	else if (!(*all))
		end(*all);
	else if (!exe)
		return ((*all)->status);
	// if (exe->pip)
	// 	return (ft_execpip(exe, all));
	return (ft_exec(exe, all));
}
