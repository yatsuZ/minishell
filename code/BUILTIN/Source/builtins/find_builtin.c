/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:55:07 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 10:23:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_builtin	find_builtin(char *str)
{
	if (!str)
		return (NON_BUILTIN);
	if (ft_strcpm(str, "cd"))
		return (CD);
	if (ft_strcpm(str, "echo"))
		return (ECHO);
	if (ft_strcpm(str, "env"))
		return (ENV);
	if (ft_strcpm(str, "exit"))
		return (EXIT);
	if (ft_strcpm(str, "export"))
		return (EXPORT);
	if (ft_strcpm(str, "pwd"))
		return (PWD);
	if (ft_strcpm(str, "unset"))
		return (UNSET);
	return (NON_BUILTIN);
}

int	exec_builtin(t_execute *exe, t_all_struct **all, t_builtin built)
{
	if (!exe || !all || !(*all) || built == NON_BUILTIN)
	{
		printf("ERROR EXEC de status\n");
		return (status);
	}
	if (built == CD)
		return (exec_cd(exe, all));
	if (built == ECHO)
		return (exec_echo(exe, all));
	if (built == ENV)
		return (exec_env(exe, all));
	if (built == EXIT)
		return (exec_exit(exe, all));
	if (built == EXPORT)
		return (exec_export(exe, all));
	if (built == PWD)
		return (exec_pwd(exe, all));
	if (built == UNSET)
		return (exec_unset(exe, all));
	return (status);
}

