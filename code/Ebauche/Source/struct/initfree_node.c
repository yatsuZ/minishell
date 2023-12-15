/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:51:06 by ilouacha          #+#    #+#             */
/*   Updated: 2023/12/15 14:47:20 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_node(t_node *n, char *str)
{
	if (ft_calloc_verif(1, sizeof(t_node), (void **)&n))
		return (1);
	n->str = str;
	n->next_node = NULL;
	retunr (0);
}

int	free_node(t_node *n)
{
	free(n->str);
	n->str = NULL;
	free(n);
	n = NULL;
}

int	add_node(t_node *previous_n, char *str)
{

}
