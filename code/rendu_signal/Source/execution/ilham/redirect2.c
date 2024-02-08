/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:09:00 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/05 18:28:56 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

void	close_fd_child(t_execute *exe)
{
	if (exe->fd_in >= 0)
	{
		dup2(exe->fd_in, STDIN_FILENO);
		close_fd(&(exe->fd_in));
	}
	if (exe->fd_out >= 0)
	{
		dup2(exe->fd_out, STDOUT_FILENO);
		close_fd(&(exe->fd_out));
	}
	close_fd(&(exe->fd[0]));
	close_fd(&(exe->fd[1]));
}
