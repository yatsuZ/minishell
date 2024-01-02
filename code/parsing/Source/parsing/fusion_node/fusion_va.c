/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/02 17:24:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	fail_key(t_env *all_va, t_node *pres, t_node *pass)
{
	t_node	*futur;

	futur = pres->next_node;
	if (pass && (pass->type_input == NON_DEFINI || pass->type_input == STR || pass->type_input == F_RD))
	{
		fusion_node(pass, -1);
		pres = pass;
	}
	else if (pass && pass->type_input == DOUBLE_COTE && futur &&(futur->type_input == STR || futur->type_input == DOUBLE_COTE))
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

static void	is_va(t_env *all_va, t_node *pres, t_node *pass)
{
	t_node	*futur;
	char	*value;
	t_node	*new_pres;

	futur = pres->next_node;
	if (futur == NULL || is_a_legit_va_env(futur->str) == FALSE)
		return (fail_key(all_va, pres, pass));
	value = get_value(all_va, futur->str);
	new_pres = no_define_to_node2(value, 0, 0);
	if (pass && (pass->type_input == STR || pass->type_input == DOUBLE_COTE || pass->type_input == F_RD))
		fusion_node(pres, STR);
	else
		fusion_node(pres, NON_DEFINI);
	futur = pres->next_node;
	remplace_node(&pres, new_pres, &pass, futur);
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
