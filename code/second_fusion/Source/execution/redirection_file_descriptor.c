/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_file_descriptor.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:54:29 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/02 20:26:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	get_here_doc_fd(t_redirecte *rd)
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

static int	fd_open(t_redirecte *tmp)
{
	if (tmp == NULL)
		return (0);
	if (tmp->type_rd ==  R_IN )
		tmp->fd = open(tmp->str_file, O_RDONLY);
	else if (tmp->type_rd == R_IN_LIMIT)
		get_here_doc_fd(tmp);
	else if (tmp->type_rd ==  R_OUT)
		tmp->fd = open(tmp->str_file, O_CREAT | O_TRUNC | O_WRONLY, 0666);
	else if (tmp->type_rd ==  R_OUT_ADD )
		tmp->fd = open(tmp->str_file, O_CREAT | O_APPEND | O_WRONLY, 0666);
	return (tmp->fd < 0);
}

int get_rd_file(t_execute *exe, t_redirecte *all_rd)
{
	if (!all_rd || !exe)
		return (0);
	if (fd_open(all_rd))
		return (1);
}