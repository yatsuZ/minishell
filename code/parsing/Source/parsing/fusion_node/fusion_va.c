/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/05 02:27:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	fail_key(t_env *all_va, t_node *pres, t_node *pass)
{
	t_node	*futur;

	futur = pres->next_node;
	if (pass && (pass->type_input == NON_DEFINI || \
	pass->type_input == STR || pass->type_input == F_RD))
	{
		fusion_node(pass, -1);
		pres = pass;
	}
	else if (pass && pass->type_input == DOUBLE_COTE && \
	futur && (futur->type_input == STR || futur->type_input == DOUBLE_COTE))
		pres->type_input = STR;
	else
		pres->type_input = NON_DEFINI;
	futur = pres->next_node;
	if (futur && (futur->type_input == STR || futur->type_input == NON_DEFINI))
		fusion_node(pres, -1);
	futur = pres->next_node;
	if (futur && (futur->type_input == STR || futur->type_input == NON_DEFINI))
		fusion_node(pres, -1);
	fusion_va(all_va, pres->next_node, pres);
}

static void	quick_define(t_node *n)
{
	while (n)
	{
		if (n->str[0] == ' ' || n->str[0] == '\t')
			n->type_input = SEPARATOR;
		else
			n->type_input = NON_DEFINI;
		n = n->next_node;
	}
}

static void	is_va(t_env *all_va, t_node *pres, t_node *pass)
{
	t_node	*key;
	char	*value;
	t_node	*new_pres;

	key = pres->next_node;
	if (key == NULL || is_a_legit_va_env(key->str) == FALSE)
		return (fail_key(all_va, pres, pass));
	value = get_value(all_va, key->str);
	new_pres = no_define_to_node2(value, 0, 0);
	quick_define(new_pres);
	if (pass && (pass->type_input == STR || \
	pass->type_input == DOUBLE_COTE || pass->type_input == F_RD))
		fusion_node(pres, STR);
	else
		fusion_node(pres, NON_DEFINI);
	key = pres->next_node;
	remplace_node(&pres, new_pres, &pass, key);
	fusion_va(all_va, pres->next_node, pres);
}

void	fusion_va(t_env *all_va, t_node *present, t_node *previous)
{
	if (!present)
		return ;
	if (present->type_input == VA_ENV)
	{
		is_va(all_va, present, previous);
		return ;
	}
	fusion_va(all_va, present->next_node, present);
	return ;
}
