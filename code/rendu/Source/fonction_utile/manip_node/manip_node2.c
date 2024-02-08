/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:47:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 01:43:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

t_node	*no_define_to_node2(char *str, size_t i_start, size_t i_end, int *err)
{
	t_node	*nn;

	nn = NULL;
	while (!(*err) && str && str[i_end])
	{
		if (is_space(str, i_end) != 0)
		{
			i_start = i_end;
			i_end = i_end + is_separator(str, i_start);
			add_last_node(&nn, ft_strcut(str, i_start, i_end, err), err);
		}
		if (is_space(str, i_end) == 0 && str[i_end])
		{
			i_start = i_end;
			while (is_space(str, i_end) == 0 && str[i_end])
				i_end++;
			add_last_node(&nn, ft_strcut(str, i_start, i_end, err), err);
			i_start = i_end;
		}
	}
	if (!(*err) && !nn)
		add_last_node(&nn, NULL, err);
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

int	remplace_node(t_node **old, t_node *new, \
t_node **previous, t_node *next)
{
	int		err;
	t_node	*last_new;

	err = 0;
	free_2str(&((*old)->str), NULL);
	**old = *new;
	if (previous && (*previous))
	{
		if ((*previous)->type_input == (*old)->type_input)
		{
			fusion_node((*previous), -1, &err);
			*old = *previous;
		}
	}
	last_new = get_last_node(*old);
	last_new->next_node = next;
	if (!err && next && last_new->type_input == next->type_input)
		fusion_node(last_new, -1, &err);
	if (!err && previous && (*previous))
		index_update((*previous));
	return (free(new), new = NULL, err);
}

t_node	*no_define_to_node(t_node **nodef, t_node **prev, int *err)
{
	t_node	*present;
	t_node	*next;
	t_node	*i;

	if (*err || have_space((*nodef)->str, 0) == FALSE)
		return ((*nodef));
	next = (*nodef)->next_node;
	present = no_define_to_node2((*nodef)->str, 0, 0, err);
	if (*err)
		return ((*nodef));
	i = present;
	while (i)
	{
		if (i->str[0] == ' ' || i->str[0] == '\t')
			i->type_input = SEPARATOR;
		else
			i->type_input = NON_DEFINI;
		i = i->next_node;
	}
	*err = remplace_node(nodef, present, prev, next);
	free_2str(&(*prev)->str, NULL);
	free(prev);
	prev = NULL;
	*nodef = present;
	return ((*nodef));
}

int	good_condition_fusion_rd_with_pip(t_node *n, t_node *next, int *nbr_pip)
{
	if (!n || !next || !(ft_strcpm(n->str, "|")))
		return (0);
	*nbr_pip = *nbr_pip - 1;
	n->type_input = NON_DEFINI;
	if (next->type_input == NON_DEFINI || next->type_input == CMD || \
	next->type_input == ARG)
		return (!(ft_strcpm(next->str, ">") || ft_strcpm(next->str, ">>") || \
		ft_strcpm(next->str, "<") || ft_strcpm(next->str, "<<") || \
		ft_strcpm(next->str, "|")));
	return (0);
}
