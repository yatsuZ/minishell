/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/18 15:36:03 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	child_process(t_data *data, t_execute *exe, int i)
{
	redirect(data, i);
	//data->cmds = ft_split(cmds[i], ' ');
	data->cmds == {&exe->cmd, exe->arg};
	if (data->cmds == NULL)
		free_all_data(data, 1, 2);
	data->cmdpath = access_check(data->env, exe->cmd);
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
		//ft_putstr_fd("heredoc>: ", 1);
		//line = get_next_line(0, 1);
		line = readline("heredoc>: ")
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
	data->nb_cmd = all->prompt->nbr_of_pip + 1;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->env = get_paths_from_environment(get_path_var(env));
	if (data->env == NULL)
		exit(1);
	data->pids = malloc(sizeof(int) * data->nb_cmd);
	if (data->pids == NULL)
		return (free_tab(data->env), exit(1));
}

int	count_hdoc(t_redirecte *all_rd)
{
	t_redirecte	*tmp;
	int			count;

	count = 0;
	while (tmp)
	{
		if (tmp->type_rd == R_IN_LIMIT)
			count ++;
		tmp = tmp->next;
	}
	return (count);
}
/**
 * @brief each iteration, we have a command to execute, so we have to precise the
 * input file, the outfile, the cmd and its arguments; besides we have to precise whether
 * there is a here_doc or not, to open all the outfiles, and define the fd_in and fd_out
 * ATTENTION: 1) les here_doc doivent s'executer dans des forks, a voir !
 * 			  2) le cas ou il y a une commande simple sans pipe !
 * 			  3) on peut avoir plusieurs here_doc, d'ou f_h est un vecteur 
 * 			a dimensionner
 * @param data 
 * @param all 
 * @param env 
 */
void	init_data(t_data *data, t_execute *exe, *env)
{
	t_redirecte	*tmp_rd;

	tmp_rd = exe->all_rd;
	data->fd_h = malloc(sizeof(int) * count_hdoc())
	if (all_rd->type_rd == R_IN_LIMIT)
	{
		data->limiter = all_rd->str_file;
		if (data->limiter == NULL)
			exit(1);
		here_doc(data);
	}
	else if (all_rd->type_rd == )
}

void	loop_cmd(t_data *data, t_execute *exe, )
{
	int	i;

	i = -1;
	while (++i < data->nb_cmd)
	{
		data->j = i;
		if (i == 0)
		
		if ((i != data->nb_cmd - 1) && pipe(data->fd) == -1)
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
		data->
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
