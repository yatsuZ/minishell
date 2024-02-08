/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 01:58:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static int	del_failure(t_node **dolar, t_node **key)
{
	int		err
	char	*tmp;

	err = 0;
	if (!(*key))
		return (err);
	if ((*key)->type_input == SINGLE_COTE || (*key)->type_input == DOUBLE_COTE)
		return (free_2str(&((*dolar)->str), NULL), \
		(*dolar)->str = ft_strdup("", &err), err);
	if (!err && ((*key)->str[0] >= '0' || (*key)->str[0] <= '9'))
	{
		tmp = ft_strcut((*key)->str, 1, ft_strlen((*key)->str), &err);
		free_2str(&((*dolar)->str), &(*key)->str);
		if (err)
			(*dolar)->str = NULL;
		else
			(*dolar)->str = ft_strdup("", &err);
		(*key)->str = tmp;
	}
	return (err);
}

static int	fail_key(t_env *all_va, t_node *pres, t_node *pass, int status)
{
	t_node	*futur;
	int		err;

	err = 0;
	futur = pres->next_node;
	del_failure(&pres, &pres->next_node);
	if (pass && (pass->type_input == NON_DEFINI || \
	pass->type_input == STR || pass->type_input == F_RD || \
	pass->type_input == F_RD2))
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
	fusion_va(all_va, pres->next_node, pres, status);
}

static void	quick_define(t_node *n)
{
	while (n)
	{
		if (n->str && (n->str[0] == ' ' || n->str[0] == '\t'))
			n->type_input = SEPARATOR;
		else
			n->type_input = NON_DEFINI;
		n = n->next_node;
	}
}

static int	is_va(t_env *all_va, t_node *pres, t_node *pass, int status)
{
	t_node	*key;
	char	*value;
	t_node	*new_pres;

	key = pres->next_node;
	if (key == NULL || is_a_legit_va_env(key->str) == FALSE)
		return (fail_key(all_va, pres, pass, status));
	value = get_value(all_va, key->str, status);
	new_pres = no_define_to_node2(value, 0, 0);
	free_2str(&value, NULL);
	quick_define(new_pres);
	if (!pass || (pass->type_input == STR || \
	pass->type_input == DOUBLE_COTE || pass->type_input == F_RD))
		fusion_node(pres, STR);
	else
		fusion_node(pres, NON_DEFINI);
	key = pres->next_node;
	remplace_node(&pres, new_pres, &pass, key);
	new_pres = NULL;
	fusion_va(all_va, pres->next_node, pres, status);
}

int	fusion_va(t_env *all_va, t_node *present, t_node *previous, int status)
{
	if (!present)
		return (0);
	if (present->type_input == VA_ENV)
		return (is_va(all_va, present, previous, status));
	return (fusion_va(all_va, present->next_node, present, status));
}
