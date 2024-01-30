/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/31 00:10:46 by yzaoui           ###   ########.fr       */
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
void	child_process(t_all_struct *all, t_execute *exe, int i)
{
	char	*cmdpath;
	redirect_pipe(all, exe, i);
	redirect(all, exe);
	exe->cmds = ft_concat_cmds(exe->cmd, exe->arg);
	if (exe->cmds == NULL)
		free_all_data(all, 2);
	cmdpath = find_cmd2(NULL, exe->cmd, &all);
	if (cmdpath)
	{
		execve(cmdpath, exe->cmds, all->env);
		free_2str(&cmdpath, NULL);
		free_all_data(all, 3);
	}
	else
		free_all_data(all, 4);
	exit(1);
}

void	init_data(t_all_struct *all)
{
	all->nb_cmds = all->prompte->nbr_of_pip + 1;
	all->prev = -1;
	all->pids = ft_calloc(all->nb_cmds, sizeof(int));
	if (all->pids == NULL)
		return (all->err = 1, free_table(all->env), end(all));
	
}

void	loop_cmd(t_execute *exec, t_all_struct *all)
{
	int	i;

	i = -1;
	while (++i < all->nb_cmds && exec)
	{
		exec->index = i;
		if ((i != all->nb_cmds - 1) && pipe(exec->fd) == -1)
		{
			free_all_data(all, i);
		}
		all->pids[i] = fork();
		if (all->pids[i] == -1)
		{
			free_all_data(all, i);
		}
		if (all->pids[i] == 0)
			child_process(all, exec, i);
		else
		{
			close_fd(&exec->fd[1]);
			close_fd(&all->prev);
			all->prev = exec->fd[0];
		}
		exec = exec->pip;
	}
	i = -1;
	while (++i < all->nb_cmds)
		waitpid(all->pids[i], NULL, 0);
}

int	execute(t_all_struct *all)
{
	init_data(all);
	loop_cmd(all->exe, all);
	free_all_data(all, 4);
	return (0);
}

