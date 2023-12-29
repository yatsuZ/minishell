/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_rd_and_pip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:46:35 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/29 20:12:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

static void	cancel_va(t_node *n)
{
	n->type_input = STR;
	while (n->next_node->type_input != DOUBLE_COTE)
		fusion_node(n, STR);
}

static int	find_all_pip(t_node *n, t_type_input previous, int nbr_pip)
{
	if (!n)
		return (nbr_pip);
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, "|"))
	{
		n->type_input = PIP;
		if (previous == PIP)
		{
			if (n->index <= 1)
				return (-5);
			return (-3);
		}
		else if (n->next_node == NULL || \
		(n->next_node->type_input == SEPARATOR && \
		n->next_node->next_node == NULL))
			return (-4);
		return (find_all_pip(n->next_node, PIP, nbr_pip + 1));
	}
	if (n->type_input != SEPARATOR)
		previous = n->type_input;
	return (find_all_pip(n->next_node, previous, nbr_pip));
}
static int	find_all_rd(t_node *n, t_type_input previous, int nbr_rd);

static int	find_file_rd(t_node *n, t_type_input previous, int nbr_rd)
{
	if (n != NULL && n->type_input == SEPARATOR)
		n = n->next_node;
	if (!n)
		return (-6);
	if (ft_strcpm(n->str, ">") || ft_strcpm(n->str, ">>") || \
	ft_strcpm(n->str, "<") || ft_strcpm(n->str, "<<"))
		return (-7);
	nbr_rd++;
	if (n->type_input == NON_DEFINI)
		n->type_input = F_RD;
	else if (previous == R_IN_LIMIT && n->type_input == DOUBLE_COTE)
		cancel_va(n->next_node);
	return (find_all_rd(n->next_node, n->type_input, nbr_rd));
}

static int	find_all_rd(t_node *n, t_type_input previous, int nbr_rd)
{
	if (!n)
		return (nbr_rd);
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, ">"))
	{
		n->type_input = R_OUT;
		return (find_file_rd(n->next_node, n->type_input, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, ">>"))
	{
		n->type_input = R_OUT_ADD;
		return (find_file_rd(n->next_node, n->type_input, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, "<"))
	{
		n->type_input = R_IN;
		return (find_file_rd(n->next_node, n->type_input, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, "<<"))
	{
		n->type_input = R_IN_LIMIT;
		return (find_file_rd(n->next_node, n->type_input, nbr_rd));
	}
	if (n->type_input != SEPARATOR)
		previous = n->type_input;
	return (find_all_rd(n->next_node, previous, nbr_rd));
}

int	find_all_rd_and_pip(t_prompt *p)
{
	p->nbr_of_pip = find_all_pip(p->all_cmd_line, PIP, 0);
	if (p->nbr_of_pip < 0)
		return (p->nbr_of_pip * -1);
	p->nbr_of_rd = find_all_rd(p->all_cmd_line, PIP, 0);
	if (p->nbr_of_rd < 0)
		return (p->nbr_of_rd * -1);
	return (0);
}
