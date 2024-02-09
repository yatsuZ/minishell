/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:27:39 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 22:00:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

t_redirecte	*init_redirecte(t_node *f_n, t_type_input t_rd, int *err)
{
	t_redirecte	*res;

	res = ft_calloc(1, sizeof(t_redirecte));
	if (!res)
		return (*err = 1, res);
	res->str_file = ft_strdup(f_n->str, err);
	if (*err)
		return (res);
	res->type_rd = t_rd;
	res->error = 0;
	if (f_n->type_input == F_RD2)
		res->va_activate = 1;
	else
		res->va_activate = 0;
	res->next = NULL;
	return (res);
}

void	free_redirection(t_redirecte *rd)
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

int	add_rd(t_redirecte **all_rd, t_type_input t_rd, t_node *f_n)
{
	int	err;

	if (*all_rd == NULL)
	{
		err = 0;
		(*all_rd) = init_redirecte(f_n, t_rd, &err);
		return (err);
	}
	return (add_rd(&((*all_rd)->next), t_rd, f_n));
}
