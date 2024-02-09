/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:26:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 21:26:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

t_execute	*init_execute(char *cmd, char **arg, t_redirecte *rd, int *err)
{
	t_execute	*res;

	res = ft_calloc(1, sizeof(t_execute));
	if (!res)
		return (*err = 1, res);
	res->index = 0;
	res->cmd = ft_strdup(cmd, err);
	if (*err)
		return (res);
	res->arg = arg;
	res->all_rd = rd;
	res->argc = 0;
	res->fd = ft_calloc(2, sizeof(int));
	if (res->fd == NULL)
		return (*err = 1, res);
	res->fd[0] = -1;
	res->fd[1] = -1;
	res->fd_in = -1;
	res->fd_out = -1;
	res->pip = NULL;
	return (res);
}

void	free_execute(t_execute *res)
{
	if (!res)
		return ;
	close_fd_child(res);
	if (res->all_rd)
		free_redirection(res->all_rd);
	free_tab(&(res->arg));
	if (res->fd)
		free(res->fd);
	res->fd = NULL;
	if (res->cmd)
		free(res->cmd);
	res->cmd = NULL;
	free_execute(res->pip);
	res->pip = NULL;
	free(res);
	res = NULL;
}
