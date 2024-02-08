/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_cote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:46:16 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 17:05:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	fusion_double_cote(t_node *present, int *err)
{
	t_node	*passe;
	t_node	*futur;

	passe = NULL;
	futur = present->next_node;
	while (*err == 0 && present->type_input != DOUBLE_COTE)
	{
		if (present->type_input == VA_ENV && futur->type_input == DOUBLE_COTE)
			present->type_input = STR;
		else if ((!passe || passe->type_input != VA_ENV) && \
		present->type_input == STR && futur->type_input == STR)
		{
			fusion_node(present, -1, err);
			if (*err)
				return ;
			futur = present->next_node;
		}
		else
		{
			passe = present;
			present = futur;
			futur = futur->next_node;
		}
	}
	fusion_cote(futur, err);
}

static void	fusion_single_cote(t_node *n, int *err)
{
	if (n->type_input == SINGLE_COTE)
		return (fusion_cote(n->next_node, err));
	while (*err == 0 && n->next_node->type_input != SINGLE_COTE)
		fusion_node(n, STR, err);
	fusion_cote(n->next_node->next_node, err);
}

void	fusion_cote(t_node *n, int *err)
{
	if (!n || *err)
		return ;
	if (n->type_input == DOUBLE_COTE)
		fusion_double_cote(n->next_node, err);
	else if (n->type_input == SINGLE_COTE)
		fusion_single_cote(n->next_node, err);
	else
		fusion_cote(n->next_node, err);
}
