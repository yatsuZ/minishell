/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:58:35 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/08 09:21:40 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

int	exec_builtin(t_execute *exe, t_all_struct **all, t_builtin built)
{
	if (!all)
		end(NULL);
	if (!(*all))
		end(*all);
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
	return ((*all)->status);
}

void	exec_cmd(t_cmd *exec_cmd, t_data *data)
{
	t_cmd	*head;

	head = exec_cmd;
	if (data->nbr_cmd == 1 && exec_cmd->status == 0 && exec_cmd->argc > 0)
	{
		if (builtin_env(exec_cmd->cmd) == 1)
			redir_builltin(exec_cmd, data);
		else if (!builtin_env(exec_cmd->cmd))
			exec_one_cmd(exec_cmd, data);
	}
	else if (exec_cmd->status != 0 && g_exit_code != 130 && data->nbr_cmd == 1)
		g_exit_code = 1;
	else if (exec_cmd->status != 0 && g_exit_code == 130 && data->nbr_cmd == 1)
		g_exit_code = 130;
	else if (data->nbr_cmd > 1)
		exec_pipe(exec_cmd, data, head);
	else
		return ;
}
