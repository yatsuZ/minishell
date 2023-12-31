/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:51:06 by ilouacha          #+#    #+#             */
/*   Updated: 2023/12/24 17:19:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_node(t_node **n, char *str)
{
	if (ft_calloc_verif(1, sizeof(t_node), (void **)n))
		return (1);
	(*n)->str = str;
	(*n)->next_node = NULL;
	(*n)->type_input = NON_DEFINI;
	(*n)->index = 0;
	return (0);
}

void	free_node(t_node *n)
{
	if (!n)
		return ;
	if (n->str)
		free(n->str);
	n->str = NULL;
	free(n);
	n = NULL;
}

int	add_node(t_node *previous_n, char *str)
{
	if (!previous_n)
		return (1);
	return (init_node(&(previous_n->next_node), str));
}

void	free_all_node(t_node *tete)
{
	if (!tete)
		return ;
	free_all_node(tete->next_node);
	tete->next_node = NULL;
	free_node(tete);
}

int	add_last_node(t_node **tete, char *str)
{
	int	retour;

	if (!(*tete))
		return (init_node(tete, str));
	else if (!(*tete)->next_node)
	{
		retour = add_node((*tete), str);
		if (!retour)
			(*tete)->next_node->index = (*tete)->index + 1;
		return (retour);
	}
	return (add_last_node(&(*tete)->next_node, str));
}
