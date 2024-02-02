/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/02 20:18:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

char	**ft_concat_cmds(char *cmd, char **arg)
{
	char	**res;
	int		i;

	i = 0;
	while (arg && arg[i])
		i++;
	res = ft_calloc(i + 2, sizeof(char *));
	res[0] = ft_strdup(cmd);
	i = 0;
	while (arg && arg[i])
	{
		res[1 + i] = ft_strdup(arg[i]);
		i++;
	}
	return (res);
}
int	child_process(t_all_struct **all, t_execute *exe, int i)
{
	int		status;
	char	*cmdpath;

	if (i != -2)
		redirect_pipe(*all, exe, i);
	if (redirect(exe))
		return (1);
	status = 0;
	if (find_builtin(exe->cmd) != NON_BUILTIN)
		status = exec_builtin(exe, all, find_builtin(exe->cmd));
	else if (exe->cmd)
	{
		cmdpath = find_cmd2(NULL, exe->cmd, all);
		if (cmdpath)
		{
			status = execve(cmdpath, exe->arg, (*all)->env);
			free_2str(&cmdpath, NULL);
		}
	}
	return (status);
}

int	init_data(t_all_struct *all)
{
	all->nb_cmds = all->prompte->nbr_of_pip + 1;
	all->prev = -1;
	if (all->nb_cmds == 1 && find_builtin(all->exe->cmd) != NON_BUILTIN)
		return (1);
	all->pids = ft_calloc(all->nb_cmds, sizeof(int));// a verifier
	return (0);
}

void	loop_cmd(t_execute *exec, t_all_struct **all)
{
	int	i;
	int	status;

	i = -1;
	while (++i < (*all)->nb_cmds && exec)
	{
		exec->index = i;
		if ((i != (*all)->nb_cmds - 1) && pipe(exec->fd) == -1)
		{
			free_all_data((*all), i);
			exit(52);
		}
		(*all)->pids[i] = fork();
		if ((*all)->pids[i] == 0)
		{
			status = child_process(all, exec, i);
			exit(status);
		}
		// else
		// {
		// 	close_fd(&(exec->fd[1]));
		// 	close_fd(&((*all)->prev));
		// 	(*all)->prev = exec->fd[0];
		// }
		exec = exec->pip;
	}
	i = -1;
	while (++i < (*all)->nb_cmds)
		waitpid((*all)->pids[i], NULL, 0);
	if ((*all)->prev != -1)
	{
		close((*all)->prev);
		(*all)->prev = -1;
	}
}

int	execute(t_all_struct **all)
{
	// Si bultin et 1 commande 
	int	fd_in;
	int	fd_out;
	int	status;
	
	if (init_data(*all))
	{
		fd_in = dup(STDIN_FILENO);
		fd_out = dup(STDOUT_FILENO);
		status = child_process(all, (*all)->exe, -2);
		dup2(fd_out, STDOUT_FILENO);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		close(fd_out);
		return (status);
	}
	loop_cmd((*all)->exe, all);
	free_all_data(*all, 4);
	return (0);
}

