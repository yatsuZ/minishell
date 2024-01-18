/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:23:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 10:24:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

//partie importante je vais juste moccupe des builtin
int	ft_exec(t_execute *exe, t_all_struct **all)
{
	if (!all || !(*all) || !exe)
		return (status);
	// faire les builtins
	if (find_builtin(exe->cmd) != NON_BUILTIN)
	{
		status = exec_builtin(exe, all, find_builtin(exe->cmd));
		return (ft_exec(exe->pip, all));
	}
	return (ft_exec(exe->pip, all));
}
