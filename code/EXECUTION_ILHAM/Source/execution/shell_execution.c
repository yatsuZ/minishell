/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/16 16:05:40 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	child_process(t_data *data, t_execute *exe, int i)
{
	redirect(data, i);
	//data->cmds = ft_split(cmds[i], ' ');
	data->cmds == {exe->cmd, exe->arg};
	if (data->cmds == NULL)
		free_all_data(data, 1, 2);
	data->cmdpath = access_check(data->env, data->cmds[0]);
	if (data->cmdpath != NULL)
	{
		execve(data->cmdpath, data->cmds, data->env);
		free_all_data(data, 1, 3);
	}
	free_all_data(data, 1, 4);
}

void	here_doc(t_data *data)
{
	char	*line;

	if (pipe(data->fd) == -1)
		exit(1);
	while (1)
	{
		ft_putstr_fd("heredoc>: ", 1);
		line = get_next_line(0, 1);
		if (line == NULL || ft_strcmp(data->limiter, line) == 0)
			break ;
		write(data->fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	get_next_line(0, 0);
	close_fd(&data->fd[1]);
	free(data->limiter);
	data->fd_h = data->fd[0];
}

void	init(t_data *data, t_all_struct *all, t_env *env)
{
	if (!all)
		exit(1);
	/*if (ac < 5)
		return (ft_putstr_fd("Not enough arguments", 2), exit(1));
	data->fd_h = -1;
	if (ft_strcmp(av[1], "here_doc") == 0 && ac > 5)
	{
		data->here_doc = 1;
		data->limiter = ft_strjoin(av[2], "\n");
		if (data->limiter == NULL)
			exit(1);
		here_doc(data);
	}
	else if (ft_strcmp(av[1], "here_doc") == 0 && ac < 6)
		return (ft_putstr_fd("Not enough arguments", 2), exit(1));*/
	data->nb_cmd = all->prompt->nbr_of_pip + 1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->env = get_paths_from_environment(get_path_var(env));
	if (data->env == NULL)
		exit(1);
	data->infile = av[1];
	data->outfile = av[ac - 1];
	data->pids = malloc(sizeof(int) * data->nb_cmd);
	if (data->pids == NULL)
		return (free_tab(data->env), exit(1));
}
/**
 * @brief each iteration, we have a command to execute, so we have to precise the
 * input file, the outfile, the cmd and its arguments; besides we have to precise whether
 * there is a here_doc or not, to open all the outfiles, and define the fd_in and fd_out
 * ATTENTION: les here_doc doiven s'executer dans des forks
 * @param data 
 * @param all 
 * @param env 
 */
void	init_data(t_data *data, t_execute *exe, t_redirecte *all_rd, char **env)
{
	
	if (all_rd->type_rd == R_IN_LIMIT)
	{
		data->limiter = ;
		if (data->limiter == NULL)
			exit(1);
		here_doc(data);
	}
	else if (all_rd->type_rd == )
}

void	loop_cmd(t_data *data, t_execute *exe, )
{
	int	i;

	i = 0;
	while (++i < data->len)
	{
		data->j = i;
		if ((i != data->len - 1) && pipe(data->fd) == -1)
			free_all_data(data, 1, i);
		data->pids[i] = fork();
		if (data->pids[i] == -1)
			free_all_data(data, 1, i);
		if (data->pids[i] == 0)
			child_process(data, exe->cmds, i);
		else
		{
			close_fd(&data->fd[1]);
			close_fd(&data->fd_h);
			close_fd(&data->prev);
			data->prev = data->fd[0];
		}
	}
	i = -1;
	while (++i < data->nb_cmd)
		waitpid(data->pids[i], NULL, 0);
}

/**
 * initialiser la structure: recuperer le chemin de la commande
 * savoir si elle est executable avec access
 * l'executer avec ses arguments
 * gérer les exceptions en termes de redirections de fichiersn 
 * comme elle serait prioritaire % aux pipes
*/


int	execute(t_all_struct *all)
{
	static t_data	data = {.prev = -1, 0};

	init(all, &data, env);
	loop_cmd(&data, av);
	free_all_data(&data, 0, 4);
 }
