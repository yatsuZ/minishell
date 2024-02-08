/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:29:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 16:37:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

int	find_file_rd2(t_node *n, int limit, int *nbr_pip)
{
	int		err;
	char	*tmp;

	err = 0;
	if (n->type_input == NON_DEFINI || n->type_input == PIP)
	{
		if (limit && good_condition_fusion_rd_with_pip(n, n->next_node, nbr_pip))
		{
			fusion_node(n, NON_DEFINI, &err);
			tmp = ft_strcut(n->str, 1, ft_strlen(n->str), &err);
			if (err)
				return (err);
			free_2str(&(n->str), NULL);
			n->str = tmp;
		}
		if (limit)
			n->type_input = F_RD2;
		if (n->type_input == NON_DEFINI)
			n->type_input = F_RD;
	}
	return (err);
}
