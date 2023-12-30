/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_and_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:37:37 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/30 19:18:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static t_boolean	is_r(t_type_input type)
{
	if (type == R_IN || type == R_IN_LIMIT || \
	type == R_OUT || type == R_OUT_ADD)
		return (TRUE);
	return (FALSE);
}

static int	cmd_or_arg(t_node *n, t_type_input p, int o)
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
		printf("%d\t%s\n", o, n->str);
	}
	else
		n->type_input = F_RD;
	return (o);
}

void	find_cmd_and_arg(t_node *node, t_type_input previous, int option)
{
	if (!node)
		return ;
	if (node->type_input == NON_DEFINI)
	{
		option = cmd_or_arg(node, previous, option);
	}
	else if (node->type_input == DOUBLE_COTE || node->type_input == SINGLE_COTE)
	{
		node = node->next_node;
		option = cmd_or_arg(node, previous, option);
		node = node->next_node;
	}
	if (node->type_input != SEPARATOR)
		previous = node->type_input;
	if (previous == PIP)
		option = 0;
	find_cmd_and_arg(node->next_node, previous, option);
}
