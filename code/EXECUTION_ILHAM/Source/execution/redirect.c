/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/16 15:18:48 by ilouacha         ###   ########.fr       */
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

void	redirect(t_data *data, t_execute *exe)



