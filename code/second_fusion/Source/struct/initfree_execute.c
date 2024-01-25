/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:26:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/25 02:16:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

t_execute	*init_execute(char *cmd, char **arg, t_redirecte *rd, int *err)
{
	t_execute	*res;

	res = ft_calloc(1, sizeof(t_execute));
	if (!res)
		return (*err = 1, res);
	res->cmd = ft_strdup(cmd);
	res->arg = arg;
	res->nbr_arg = 0;
	res->all_rd = rd;
	return (res);
}

void	free_execute(t_execute *res)
{
	size_t	i;

	i = 0;
	if (!res)
		return ;
	if (res->all_rd)
		free_redirection(res->all_rd);
	if (res->arg)
	{
		while (res->arg[i])
		{
			free(res->arg[i]);
			res->arg[i] = NULL;
		}
		free(res->arg);
		res->arg = NULL;
	}
	if (res->cmd)
		free(res->cmd);
	res->cmd = NULL;
	free_execute(res->pip);
	res->pip = NULL;
	free(res);
	res = NULL;
}
