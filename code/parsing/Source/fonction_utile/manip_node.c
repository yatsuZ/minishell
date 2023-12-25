/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:26 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/25 22:35:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	index_update(t_node *n)
{
	t_node	*index_n;

	if (!n)
		return ;
	index_n = n->next_node;
	while (index_n)
	{
		index_n->index = index_n->index - 1;
		index_n = index_n->next_node;
	}
}

void	del_node(t_node *n)
{
	t_node	*new_n;

	new_n = n->next_node;
	n->next_node = NULL;
	free_node(n);
	n = new_n;
	index_update(n);
}

// fusion le noeud actuel par le suivant et remplace
// le type sauf si new_type == -1
// fusion les str et change lindex de tout les noeud
// suivant ne fais rien ren si il na pas de noeud suivant
void	fusion_node(t_node *n, int new_type)
{
	char	*new_str;

	if (n->next_node == NULL)
		return ;
	new_str = ft_strjoin(n->str, n->next_node->str);
	free(n->str);
	n->str = new_str;
	del_node(n->next_node);
	if (new_type != -1)
		n->type_input = new_type;
}
