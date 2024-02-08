/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/02/07 13:43:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

void	close_fd(int *fd)
{
	if (*fd == -1)
		return ;
	if (close(*fd) != 0)
		perror("Close");
	*fd = -1;
}

int	fd_open(t_redirecte *tmp)
{
	if (tmp == NULL)
		return (0);
	if (tmp->type_rd == R_IN)
		tmp->fd = open(tmp->str_file, O_RDONLY);
	else if (tmp->type_rd == R_IN_LIMIT)
		get_here_doc_fd(tmp);
	else if (tmp->type_rd == R_OUT)
		tmp->fd = open(tmp->str_file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else if (tmp->type_rd == R_OUT_ADD)
		tmp->fd = open(tmp->str_file, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (tmp->fd == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

void	redirect_pipe(t_all_struct *all, t_execute *exe, int i)
{
	if (i == -2)
		return ;
	if (i != all->nb_cmds - 1)
	{
		close_fd(&exe->fd[0]);
		dup2(exe->fd[1], STDOUT_FILENO);
		close_fd(&(exe->fd[1]));
	}
	if (i != 0)
	{
		close_fd(&exe->fd[1]);
		dup2(all->prev, STDIN_FILENO);
		close_fd(&all->prev);
	}
}

int	redirect(t_execute *exe, int i)
{
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		if (fd_open(tmp))
			return (1);
		if (tmp->type_rd == R_IN || tmp->type_rd == R_IN_LIMIT)
		{
			if (i == -2 && exe->fd_in < 0)
				exe->fd_in = dup(STDIN_FILENO);
			dup2(tmp->fd, STDIN_FILENO);
		}
		else if (tmp->type_rd == R_OUT || tmp->type_rd == R_OUT_ADD)
		{
			if (i == -2 && exe->fd_out < 0)
				exe->fd_out = dup(STDOUT_FILENO);
			dup2(tmp->fd, STDOUT_FILENO);
		}
		close_fd(&(tmp->fd));
		tmp = tmp->next;
	}
	return (0);
}

void	get_here_doc_fd(t_redirecte *rd)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("ERROR: pipe rd in here_doc fails");
		exit(EXIT_FAILURE);
	}
	print_fd(rd->str_file, fd[1]);
	close_fd(&fd[1]);
	rd->fd = fd[0];
}
