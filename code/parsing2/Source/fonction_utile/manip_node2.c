/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:47:54 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/30 18:02:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static t_node	*no_define_to_node2(char *str, size_t i_start, size_t i_end)
{
	t_node	*nn;

	nn = NULL;
	while (str[i_end])
	{
		if (is_space(str, i_end) != 0)
		{
			i_start = i_end;
			i_end = i_end + is_separator(str, i_start);
			add_last_node(&nn, ft_strcut(str, i_start, i_end));
		}
		if (is_space(str, i_end) == 0 && str[i_end])
		{
			i_start = i_end;
			while (is_space(str, i_end) == 0 && str[i_end])
				i_end++;
			add_last_node(&nn, ft_strcut(str, i_start, i_end));
			i_start = i_end;
		}
	}
	return (nn);
}

t_node	*get_last_node(t_node *tete)
{
	while (tete)
	{
		if (tete->next_node == NULL)
			return (tete);
		tete = tete->next_node;
	}
	return (tete);
}

void	remplace_node(t_node **old, t_node *new, \
t_node **previous, t_node *next)
{
	t_node	*last_new;

	if (previous && (*previous))
	{
		(*previous)->next_node = new;
		if ((*previous)->type_input == new->type_input)
		{
			fusion_node((*previous), -1);
			new = (*previous);
		}
	}
	last_new = get_last_node(new);
	last_new->next_node = next;
	if (next && last_new->type_input == next->type_input)
		fusion_node(last_new, -1);
	if (previous && (*previous))
		index_update((*previous));
	else
		index_update(new);
	(*old) = new;
}

t_node	*no_define_to_node(t_node **nodef, t_node **prev)
{
	t_node	*present;
	t_node	*next;
	t_node	*i;

	if (have_space((*nodef)->str, 0) == FALSE)
		return ((*nodef));
	next = (*nodef)->next_node;
	present = no_define_to_node2((*nodef)->str, 0, 0);
	i = present;
	while (i)
	{
		if (i->str[0] == ' ' || i->str[0] == '\t')
			i->type_input = SEPARATOR;
		else
			i->type_input = NON_DEFINI;
		i = i->next_node;
	}
	remplace_node(nodef, present, prev, next);
	*nodef = present;
	return ((*nodef));
}
