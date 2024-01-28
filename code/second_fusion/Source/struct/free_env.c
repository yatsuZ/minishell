/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:36:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/28 15:48:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	free_env(t_env **env)
{
	if (!env)
		return ;
	free_2str(&((*env)->key), &((*env)->value));
	(*env)->next_va = NULL;
	free(*env);
	(*env) = NULL;
}


void	update_env(t_all_struct **all)
{
	size_t	nbr_of_va;
	t_env	*all_va;

	if (!all || !(*all))
		return ;
	if ((*all)->env)
		free_tab(&((*all)->env));
	all_va = (*all)->all_va;
	nbr_of_va = 0;
	while (all_va)
	{
		if (all_va->show && all_va->value)
			nbr_of_va++;
		all_va = all_va->next_va;
	}
	(*all)->env = creat_env(nbr_of_va, (*all)->all_va);
}
