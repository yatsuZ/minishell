/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_cote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:46:16 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 21:39:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	fusion_double_cote(t_node *n)
{
	if (n->type_input == VA_ENV)
	{
		n = n->next_node;
		if (n->type_input == DOUBLE_COTE)
			return (fusion_cote(n->next_node));
		else
			n = n->next_node;
	}
	if (n->type_input == DOUBLE_COTE)
		return (fusion_cote(n->next_node));
	while (n->next_node->type_input != DOUBLE_COTE)
	{
		if (n->next_node->type_input == VA_ENV) //[X]->[] == $
		{
			n = n->next_node;// [X]->[$]
			if (n->next_node->type_input == DOUBLE_COTE) // [$]->[] == "
				return (fusion_cote(n->next_node->next_node));// [$]->["]->[X]
			n = n->next_node->next_node;//[$]->[KEY]->[X]
			if (n->type_input == DOUBLE_COTE) //[X] == "
				return (fusion_cote(n->next_node));
		}
		else
			fusion_node(n, STR);
	}
	fusion_cote(n->next_node->next_node);
}

static void	fusion_single_cote(t_node *n)
{
	if (n->type_input == SINGLE_COTE)
		return (fusion_cote(n->next_node));
	while (n->next_node->type_input != SINGLE_COTE)
		fusion_node(n, STR);
	fusion_cote(n->next_node->next_node);
}

void	fusion_cote(t_node *n)
{
	if (!n)
		return ;
	if (n->type_input == DOUBLE_COTE)
		fusion_double_cote(n->next_node);
	else if (n->type_input == SINGLE_COTE)
		fusion_single_cote(n->next_node);
	else
		fusion_cote(n->next_node);
}
