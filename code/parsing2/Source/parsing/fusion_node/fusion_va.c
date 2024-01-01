/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/29 21:18:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	fail_key(t_env *all_va, t_node *n, t_node *prev)
{
	if (prev && (prev->type_input == NON_DEFINI || prev->type_input == STR))
	{
		fusion_node(prev, -1);
		n = prev;
	}
	else if (prev && (prev->type_input == DOUBLE_COTE))
		n->type_input = STR;
	else
		n->type_input = NON_DEFINI;
	if (n->next_node == NULL || n->next_node->type_input == DOUBLE_COTE || \
	n->next_node->type_input == SEPARATOR)
		return (fusion_va(all_va, n->next_node));
	else if (n->next_node->type_input == NON_DEFINI || \
	n->next_node->type_input == STR)
		fusion_node(n, -1);
	if (n->next_node && n->next_node->type_input == STR)
		fusion_node(n, -1);
	return (fusion_va(all_va, n->next_node));
}

static void	next_is_va(t_env *all_va, t_node *n, t_node *prev)
{
	char	*value;

	if (n->next_node == NULL || is_a_legit_va_env(n->next_node->str) == FALSE)
		return (fail_key(all_va, n, prev));
	value = get_value(all_va, n->next_node->str);
	if (prev && (prev->type_input == STR || prev->type_input == DOUBLE_COTE))
		fusion_node(n, STR);
	else
		fusion_node(n, NON_DEFINI);
	free(n->str);
	n->str = NULL;
	n->str = value;
	if (prev && (prev->type_input == NON_DEFINI || prev->type_input == STR))
	{
		fusion_node(prev, -1);
		n = prev;
	}
	if (n->next_node && \
	(n->next_node->type_input == STR || n->next_node->type_input == NON_DEFINI))
		fusion_node(n, -1);
	fusion_va(all_va, n);
}

void	fusion_va(t_env *all_va, t_node *n)
{
	if (!n || n->next_node == NULL)
		return ;
	if (n->type_input == VA_ENV)
	{
		next_is_va(all_va, n, NULL);
		return ;
	}
	else if (n->next_node->type_input == VA_ENV)
	{
		next_is_va(all_va, n->next_node, n);
		return ;
	}
	fusion_va(all_va, n->next_node);
	return ;
}
