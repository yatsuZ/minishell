/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/15 14:30:53 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	child_process(t_data *data, t_all_struct *all, int i)
{
	redirect(data, i);
	//data->cmds = ft_split(cmds[i], ' ');
    data->cmds == {all->exe->cmd, all->exe->arg};
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

void	init(t_data *data, t_all_struct *all, char **env)
{
    if (!all)
        // there is no structure
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
	data->nb_cmd = all->prompt->nbr_of_pip;// +1?
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->env = get_paths_from_environment(get_path_var(env));
	if (data->env == NULL)
		exit(1);
	data->infile = av[1];
	data->outfile = av[ac - 1];
	data->len = ac - 1;
	data->pids = malloc(sizeof(int) * data->nb_cmd);
	if (data->pids == NULL)
		return (free_tab(data->env), exit(1));
}

void	loop_cmd(t_data *data, char **cmds)
{
	int	i;

	i = 1 + data->here_doc;
	while (++i < data->len)
	{
		data->j = i;
		if ((i != data->len - 1) && pipe(data->fd) == -1)
			free_all_data(data, 1, i);
		data->pids[i - 2 - data->here_doc] = fork();
		if (data->pids[i - 2 - data->here_doc] == -1)
			free_all_data(data, 1, i);
		if (data->pids[i - 2 - data->here_doc] == 0)
			child_process(data, cmds, i);
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
 * savoir si elle est excutable avec access
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
