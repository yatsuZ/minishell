/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:51:06 by ilouacha          #+#    #+#             */
/*   Updated: 2023/12/15 13:06:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_node(t_node **n, char *str)
{
	if (ft_calloc_verif(1, sizeof(t_node), (void **)n))
		return (1);
	(*n)->str = str;
	(*n)->next_node = NULL;
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
