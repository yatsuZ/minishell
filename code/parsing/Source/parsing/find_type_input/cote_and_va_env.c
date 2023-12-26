/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cote_and_va_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:43:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:25:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static int	previous_no_define(t_node *n)
{
	if (n->str[0] == '\"')
		n->type_input = DOUBLE_COTE;
	else if (n->str[0] == '\'')
		n->type_input = SINGLE_COTE;
	else if (n->str[0] == '\t' || n->str[0] == ' ')
		n->type_input = SEPARATOR;
	else if (n->str[0] == '$')
		n->type_input = VA_ENV;
	if (n->type_input == VA_ENV || n->type_input == SEPARATOR)
		return (find_cote_and_va(n->next_node, NON_DEFINI));
	return (find_cote_and_va(n->next_node, n->type_input));
}

static int	previous_double_cote(t_node *n)
{
	if (n->str[0] == '\"')
	{
		n->type_input = DOUBLE_COTE;
		return (find_cote_and_va(n->next_node, NON_DEFINI));
	}
	n->type_input = STR;
	if (n->str[0] == '$')
		n->type_input = VA_ENV;
	if (n->next_node == NULL)
		return (1);
	return (find_cote_and_va(n->next_node, DOUBLE_COTE));
}

static int	previous_single_cote(t_node *n)
{
	if (n->str[0] == '\'')
	{
		n->type_input = SINGLE_COTE;
		return (find_cote_and_va(n->next_node, NON_DEFINI));
	}
	n->type_input = STR;
	if (n->next_node == NULL)
		return (1);
	return (find_cote_and_va(n->next_node, SINGLE_COTE));
}

int	find_cote_and_va(t_node *n, int previous_type)
{
	if (!n)
		return (0);
	else if (previous_type == NON_DEFINI)
		return (previous_no_define(n));
	else if (previous_type == DOUBLE_COTE)
		return previous_double_cote(n);
	else if (previous_type == SINGLE_COTE)
		return previous_single_cote(n);
	return (0);
}
