/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/19 13:24:25 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	close_fd(int *fd)
{
	if (*fd == -1)
		return ;
	if (close(*fd) != 0)
		perror("Close");
	*fd = -1;
}

void	close_pipes(t_data *data)
{
	if ((data->j + 1) < data->len)
		close_fd(&data->fd[0]);
	close_fd(&data->fd[1]);
}

void	sub_redirect(t_data	*data, int fd)
{
	if (data->here_doc == 0)
		fd = open(data->infile, O_RDONLY);
	else
		fd = data->fd_h;
	if (fd == -1)
	{
		close(data->fd[0]);
		close(data->fd[1]);
		free_all_data(data, 1, 3);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

/*void	redirect(t_data	*data, int i)
{
	int	fd;

	fd = -1;
	if (i == 0 || i == data->len - 1)
		sub_redirect(data, fd);
	else
	{
		dup2(data->prev, STDIN_FILENO);
		close(data->prev);
	}
	if (i == data->len - 1)
	{
		if (data->here_doc)
			fd = open(data->outfile, O_CREAT | O_APPEND | O_WRONLY, 0666);
		else
			fd = open(data->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
		if (fd == -1)
			free_all_data(data, 1, 3);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		dup2(data->fd[1], STDOUT_FILENO);
	close_pipes(data);
}*/

void	fd_open(t_all_struct *all, t_redirecte tmp)
{
	if (tmp->type_rd ==  R_IN )
		tmp->fd = open(data->infile, O_RDONLY);
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

void	redirect(t_all_struct *all, t_execute *exe, int i)
{
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	while (tmp)
	{
		fd_open(tmp);
		if (tmp->type_rd == R_IN || tmp->type_rd == R_IN_LIMIT)
			dup2(tmp->fd, STDIN_FILENO);
		else if (tmp->type_rd == R_OUT || tmp->type_rd == R_OUT_ADD)
			dup2(tmp->fd, STDOUT_FILENO);
		close(tmp->fd);
		tmp = tmp->next;
	}
}

void	get_here_doc_fd(t_redirecte rd)
{
	if (pipe(rd->fd) == -1)
	{
		perror("ERROR: pipe rd in limit fail");
		exit(EXIT_FAILURE);
	}
	write(rd->fd[1], rd->str_file, ft_strlen(rd->str_file));
	close_fd(rd->fd[1]);
	rd->fd = rd->fd[0];
}
