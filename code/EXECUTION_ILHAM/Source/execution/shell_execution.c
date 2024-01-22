/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/19 23:24:51 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	child_process(t_all_struct *all, t_execute *exe, int i)
{
	redirect_pipe(all, exe, i);
	redirect(all, exe, i);
	exe->cmds == {&exe->cmd, exe->arg};
	if (exe->cmds == NULL)
		free_all_data(all, 1, 2);
	all->cmdpath = access_check(all->env, exe->cmd);
	if (data->cmdpath != NULL)
	{
		execve(all->cmdpath, exe->cmds, all->env);
		free_all_data(all, 1, 3);
	}
	free_all_data(all, 1, 4);
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
void	init_data(t_all_struct *all)
{
	all->cmdpath = 0;
	all->nb_cmds = all->prompte->nbr_of_pip + 1;
	all->prev = -1;
	all->env = get_paths_from_environment(get_path_var(all->all_va));
	if (all->env == NULL)
		exit(1);
	all->pids = malloc(sizeof(int) * all->nb_cmds);
	if (all->pids == NULL)
		return (free_table(all->env), exit(1));
	
}

void	loop_cmd(t_all_struct *all)
{
	int	i;
	t_execute	*exec;

	exec = all->exe;

	i = -1;
	while (++i < all->nb_cmds)
	{
		exec->index = i;
		if ((i != all->nb_cmds - 1) && pipe(exec->fd) == -1)
			free_all_data(all, 1, i);
		all->pids[i] = fork();
		if (all->pids[i] == -1)
			free_all_data(all, 1, i);
		if (all->pids[i] == 0)
			child_process(all, exec->cmds, i);
		else
		{
			close_fd(&exec->fd[1]);
			close_fd(&all->prev);
			all->prev = exec->fd[0];
		}
		exec = exec->pip;
	}
	i = -1;
	while (++i < data->nb_cmd)
		waitpid(all->pids[i], NULL, 0);
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
	init_data(all);
	loop_cmd(all);
	free_all_data(t_all_struct *all, 0, 4);
	return (EXIT_FAILURE);
}
/*
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
}*/

