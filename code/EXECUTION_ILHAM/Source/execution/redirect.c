/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:56:16 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/18 16:48:32 by ilouacha         ###   ########.fr       */
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

void	redirect(t_data *data, t_execute *exe, int i)
{
	int			fd;
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	while (tmp)
	{
		if (tmp->type_rd ==  R_IN || tmp->type_rd ==  R_IN_LIMIT)
			tmp = tmp->next;
	}
}

void	fd_open(t_data *data, t_execute *exe, int i)
{
	int			fd;
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	while (tmp)
	{
		if (tmp->type_rd ==  R_IN || tmp->type_rd ==  R_IN_LIMIT ||
				tmp->type_rd ==  R_OUT_ADD || tmp->type_rd ==  R_OUT)
		{
			fd = open(data->infile, O_RDONLY);
		}	
	}
}
void	redirecte_pipe(t_data *data, t_execute *exe, int i)
{
	
}

void	redirect_infile(t_data *data, t_execute *exe, int i)
{
	int			fd;
	t_redirecte	*tmp;

	tmp = exe->all_rd;
	while (tmp)
	{
		if (tmp->type_rd == R_IN)
		{
			data->infile = tmp->str_file;
			fd = open(data->infile, O_RDONLY);
			if (fd < 0)
				perror("open file problem !")
			dup2(fd, STDIN_FILENO);
		}
		else if (tmp->type_rd == R_IN_LIMIT)
		{
			data->fd_h = get_here_doc_fd(s_redirecte rd);
			if (fd < 0)
				perror("open file problem !")
			dup2(data->fd_h[i], STDIN_FILENO);//fd_h[i] designe le fd du dernier here_doc retenu en input
		}
		else if (tmp->type_rd == R_OUT)
		{
			data->outfile = tmp->str_file;
			fd = open(data->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0666);
			if (fd < 0)
				perror("open file problem !")
			dup2(data->prev, STDOUT_FILENO);
		}
		else if (tmp->type_rd == R_OUT_ADD)
		{
			data->outfile = here_doc();
			fd = open(data->outfile, O_CREAT | O_APPEND | O_WRONLY, 0666);
			if (fd < 0)
				perror("open file problem !")
			dup2(data->prev, STDOUT_FILENO);
		}

	}

}

				// if (pipe(rd->fd))
				// 	printf("ERROR: pipe rd in limit fail on sen occupe plus tard\n");
				// write(rd->fd[1], res, ft_strlen(res));
				// close(fd);

