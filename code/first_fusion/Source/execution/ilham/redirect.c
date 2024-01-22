/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/22 17:28:36 by yzaoui           ###   ########.fr       */
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

void	fd_open(t_all_struct *all, t_redirecte *tmp)
{
	if (tmp->type_rd ==  R_IN )
		tmp->fd = open(tmp->str_file, O_RDONLY);
	else if (tmp->type_rd == R_IN_LIMIT)
		get_here_doc_fd(tmp); // get tmp->fd = fd_h
	else if (tmp->type_rd ==  R_OUT)
		tmp->fd = open(tmp->str_file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else if (tmp->type_rd ==  R_OUT_ADD )
		tmp->fd = open(tmp->str_file, O_CREAT | O_APPEND | O_WRONLY, 0666);
	if (tmp->fd == -1)
	{
		perror("open file problem !");
		free_all_data(all, 1, 3);
	}
}

void	redirect_pipe(t_all_struct *all, t_execute *exe, int i)
{
	(void)	i;
	
	if (i != all->nb_cmds - 1)
	{
		close_fd(&exe->fd[0]);
		dup2(exe->fd[1], STDOUT_FILENO);
		close(exe->fd[1]);
	}
	if (i != 0)
	{
		close_fd(&exe->fd[1]);
		dup2(all->prev, STDIN_FILENO);
		close(all->prev);
	}
}

void	redirect(t_all_struct *all, t_execute *exe)
{
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	while (tmp)
	{
		fd_open(all, tmp);
		if (tmp->type_rd == R_IN || tmp->type_rd == R_IN_LIMIT)
			dup2(tmp->fd, STDIN_FILENO);
		else if (tmp->type_rd == R_OUT || tmp->type_rd == R_OUT_ADD)
			dup2(tmp->fd, STDOUT_FILENO);
		close(tmp->fd);
		tmp = tmp->next;
	}
}

void	get_here_doc_fd(t_redirecte *rd)
{
	int	fd[2];
	
	if (pipe(fd) == -1)
	{
		perror("ERROR: pipe rd in here_doc fails");
		exit(EXIT_FAILURE);
	}
	write(fd[1], rd->str_file, ft_strlen(rd->str_file));
	close_fd(&fd[1]);
	rd->fd = fd[0];
}
