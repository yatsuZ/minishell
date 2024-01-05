/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:27:39 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/05 16:49:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

t_redirection	*init_redirection(char *f, t_type_input t_rd, int *err)
{
	t_redirection	*res;

	res = ft_calloc(1, sizeof(t_redirection));
	if (!res)
		return (*err = 1, res);
	res->str_file = ft_strdup(f);
	res->type_rd= t_rd;
	res->next = NULL;
	return (res);
}

void	free_redirection(t_redirection *rd)
{
	if (!rd)
		return ;
	free(rd->str_file);
	rd->str_file = NULL;
	free_redirection(rd->next);
	rd->next = NULL;
	free(rd);
	rd = NULL;
}

int	add_rd(t_redirection **all_rd, t_type_input t_rd, char *f)
{
	int	err;

	if (*all_rd == NULL)
	{
		err = 0;
		(*all_rd) = init_redirection(f, t_rd, &err);
		return (err);
	}
	return (add_rd(&((*all_rd)->next), t_rd, f));
}
