/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:23:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/24 12:10:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

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
	return (ft_exec(exe, all));
	return (ft_all_exec(exe->pip, all));
}
