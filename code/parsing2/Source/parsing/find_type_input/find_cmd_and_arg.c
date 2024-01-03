/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_and_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:37:37 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/03 01:48:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static t_boolean	is_r(t_node *n)
{
	t_type_input	type;

	if (!n)
		return (FALSE);
	type = n->type_input;
	if (type == R_IN || type == R_IN_LIMIT || \
	type == R_OUT || type == R_OUT_ADD)
		return (TRUE);
	return (FALSE);
}

int	cmd_or_arg(t_node *n, t_node *p, int o)
{
	if (!is_r(p))
	{
		if (o == 0)
		{
			n->type_input = CMD;
		}
		else
		{
			n->type_input = ARG;
		}
		o = 1;
	}
	else
		n->type_input = F_RD;
	if (n->next_node && n->next_node->type_input == NON_DEFINI)
		fusion_node(n, -1);
	return (o);
}

void	find_cmd_and_arg(t_node *n, t_node *prev, int option)
{
	if (!n)
		return ;
	if (n->type_input == SEPARATOR && n->next_node \
	&& n->next_node->type_input == SEPARATOR)
		fusion_node(n, -1);
	else if (n->type_input == NON_DEFINI)
		option = cmd_or_arg(n, prev, option);
	else if (n->type_input == DOUBLE_COTE || n->type_input == SINGLE_COTE)
	{
		del_cote(prev, n, option);
		return ;
	}
	if (n->type_input != SEPARATOR)
		prev = n;
	if (prev && prev->type_input == PIP)
		option = 0;
	find_cmd_and_arg(n->next_node, prev, option);
}
