/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/09 10:08:10 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

int	child_process(t_all_struct **all, t_execute *exe, int i)
{
	int		status;
	char	*cmdpath;

	if (i != -2)
		redirect_pipe(*all, exe, i);
	if (redirect(exe, i))
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
	if (i == -2)
		return (close_fd_child(exe), status);
	return (free_all(*all), *all = NULL, status);
}

int	init_data(t_all_struct *all)
{
	all->nb_cmds = all->prompte->nbr_of_pip + 1;
	all->prev = -1;
	if (all->nb_cmds == 1)
	{
		change_va_undescore(all->exe, &(all->all_va));
		if (find_builtin(all->exe->cmd) != NON_BUILTIN)
			return (1);
	}
	all->pids = ft_calloc(all->nb_cmds, sizeof(int));
	if (!all->pids)
		printf("pids ERROR\n\n");
	return (0);
}

static void	loop_cmd(t_execute *exec, t_all_struct **all, int i, int status)
{
	while (++i < (*all)->nb_cmds && exec)
	{
		if ((i != (*all)->nb_cmds - 1) && pipe(exec->fd) == -1)
			print_fd("ERROR pip\n\n", 2);
		(*all)->pids[i] = fork();
		if ((*all)->pids[i] == 0)
		{
			signal_in_fork();
			status = child_process(all, exec, i);
			exit(status);
		}
		close_fd(&exec->fd[1]);
		close_fd(&((*all)->prev));
		(*all)->prev = dup(exec->fd[0]);
		close_fd(&(exec->fd[0]));
		exec = exec->pip;
	}
	i = -1;
	while (++i < (*all)->nb_cmds)
	{
		signal(SIGINT, SIG_IGN);
		waitpid((*all)->pids[i], &status, 0);
	}
	(*all)->status = signal_in_father(status);
}

int	execute(t_all_struct **all)
{
	int	status;

	if (init_data(*all))
	{
		status = child_process(all, (*all)->exe, -2);
		return (status);
	}
	loop_cmd((*all)->exe, all, -1, 0);
	free((*all)->pids);
	(*all)->pids = NULL;
	return (0);
}
