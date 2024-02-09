/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:06:41 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 15:00:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static int	del_failure(t_node **dolar, t_node **key)
{
	int		err;
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

static int	fail_key(t_env *all_va, t_node *mtn, t_node *pass, int status)
{
	int		err;

	err = del_failure(&mtn, &mtn->next_node);
	if (err)
		return (err);
	if (pass && (pass->type_input == NON_DEFINI || pass->type_input == STR \
	|| pass->type_input == F_RD || pass->type_input == F_RD2))
	{
		fusion_node(pass, -1, &err);
		mtn = pass;
	}
	else if (pass && pass->type_input == DOUBLE_COTE && mtn->next_node && \
	(mtn->next_node->type_input == STR || \
	mtn->next_node->type_input == DOUBLE_COTE))
		mtn->type_input = STR;
	else
		mtn->type_input = NON_DEFINI;
	if (err)
		return (err);
	return (fail_key2(all_va, mtn, status));
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

static int	is_va(t_env *all_va, t_node *mtn, t_node *pass, int status)
{
	t_node	*key;
	char	*value;
	t_node	*new_pres;
	int		err;

	err = 0;
	key = mtn->next_node;
	if (key == NULL || is_a_legit_va_env(key->str) == FALSE)
		return (fail_key(all_va, mtn, pass, status));
	value = get_value(all_va, key->str, status, &err);
	new_pres = no_define_to_node2(value, 0, 0, &err);
	if (err)
		return (1);
	free_2str(&value, NULL);
	quick_define(new_pres);
	if (!pass || (pass->type_input == STR || \
	pass->type_input == DOUBLE_COTE || pass->type_input == F_RD))
		fusion_node(mtn, STR, &err);
	else
		fusion_node(mtn, NON_DEFINI, &err);
	key = mtn->next_node;
	remplace_node(&mtn, new_pres, &pass, key);
	return (new_pres = NULL, fusion_va(all_va, mtn->next_node, mtn, status));
}

int	fusion_va(t_env *all_va, t_node *present, t_node *previous, int status)
{
	if (!present)
		return (0);
	if (present->type_input == VA_ENV)
		return (is_va(all_va, present, previous, status));
	return (fusion_va(all_va, present->next_node, present, status));
}
