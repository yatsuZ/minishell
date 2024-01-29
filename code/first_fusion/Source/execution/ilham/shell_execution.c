/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:41:18 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/29 20:06:22 by ilouacha         ###   ########.fr       */
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
	redirect_pipe(all, exe, i);
	redirect(all, exe);
	exe->cmds = ft_concat_cmds(exe->cmd, exe->arg);
	if (exe->cmds == NULL)
		free_all_data(all, 2);
	all->cmdpath = access_check(all->env, exe->cmd);
	if (all->cmdpath != NULL)
	{
		execve(all->cmdpath, exe->cmds, all->env);
		free_all_data(all, 3);
	}
	else
		free_all_data(all, 4);
	exit(1);
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
	all->nb_cmds = all->prompte->nbr_of_pip + 1;
	all->prev = -1;
	all->env = get_paths_from_environment(get_path_var(all->all_va));
	all->pids = malloc(sizeof(int) * all->nb_cmds);
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
	loop_cmd(all->exe, all);
	free_all_data(all, 4);
	return (0);
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

