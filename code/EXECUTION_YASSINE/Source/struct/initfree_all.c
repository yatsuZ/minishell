/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:06:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/05 04:48:36 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	init_minishell_signal(int *mss)
{
	(*mss) = 0;
}

int	init_all(t_all_struct **res, char **env)
{
	if (ft_calloc_verif(1, sizeof(t_all_struct), (void **)res))
		return (1);
	(*res)->err = init_all_va(&(*res)->all_va, env);
	(*res)->err = init_prompt(&(*res)->prompte);
	(*res)->exe = NULL;
	return ((*res)->err);
}

void	free_all(t_all_struct *all)
{
	if (!all)
		return ;
	free_execute(all->exe);
	free_prompt(all->prompte);
	free_all_va(all->all_va);
	free(all);
	all = NULL;
}
