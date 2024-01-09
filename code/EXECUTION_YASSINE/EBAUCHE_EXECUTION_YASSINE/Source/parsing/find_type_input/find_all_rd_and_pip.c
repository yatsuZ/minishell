/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_rd_and_pip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:46:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/09 17:21:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

void	cancel_va(t_node *n, t_type_input type)
{
	if (!n)
		return ;
	if (n->type_input == VA_ENV || n->type_input == NON_DEFINI)
	{
		n->type_input = NON_DEFINI;
		n = n->next_node;
	}
	else if (type == DOUBLE_COTE || type == SINGLE_COTE)
		n = only_str(n, n ->type_input);
	if (!n)
		return ;
	type = n->type_input;
	if (type == VA_ENV || \
	type == NON_DEFINI || \
	type == SINGLE_COTE || \
	type == DOUBLE_COTE)
		cancel_va(n, type);
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

static int	find_file_rd(t_node *n, int nbr_rd)
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
	return (find_all_rd(n->next_node, n->type_input, nbr_rd));
}

static int	find_all_rd(t_node *n, t_type_input previous, int nbr_rd)
{
	if (!n)
		return (nbr_rd);
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, ">"))
	{
		n->type_input = R_OUT;
		return (find_file_rd(n->next_node, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, ">>"))
	{
		n->type_input = R_OUT_ADD;
		return (find_file_rd(n->next_node, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, "<"))
	{
		n->type_input = R_IN;
		return (find_file_rd(n->next_node, nbr_rd));
	}
	else if (n->type_input == NON_DEFINI && ft_strcpm(n->str, "<<"))
	{
		n->type_input = R_IN_LIMIT;
		return (find_file_rd(n->next_node, nbr_rd));
	}
	if (n->type_input != SEPARATOR)
		previous = n->type_input;
	return (find_all_rd(n->next_node, previous, nbr_rd));
}

int	find_all_rd_and_pip(t_prompt *p)
{
	t_node	*n;

	p->nbr_of_pip = find_all_pip(p->all_cmd_line, PIP, 0);
	if (p->nbr_of_pip < 0)
		return (p->nbr_of_pip * -1);
	p->nbr_of_rd = find_all_rd(p->all_cmd_line, PIP, 0);
	if (p->nbr_of_rd < 0)
		return (p->nbr_of_rd * -1);
	n = p->all_cmd_line;
	while (n)
	{
		if (n->type_input == R_IN_LIMIT)
		{
			n = n->next_node;
			if (n->type_input == SEPARATOR)
				n = n->next_node;
			if (n)
				cancel_va(n, n->type_input);
		}
		else
			n = n->next_node;
	}
	return (0);
}
