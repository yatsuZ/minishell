/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:06:47 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/21 11:37:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	init_minishell_signal(int *mss)
{
	(*mss) = 0;
	// redefinir ctrl+d,+c,+/
}

int	init_all(t_all_struct **res)
{
	if (ft_calloc_verif(1, sizeof(t_all_struct), (void **)res))
		return (1);
	init_minishell_signal(&((*res)->minishell_signal));// A FAIRE
	(*res)->err = init_prompt(&(*res)->prompte);
	return ((*res)->err);
}

void	free_all(t_all_struct *all)
{
	if (!all)
		return ;
	free_prompt(all->prompte);
	free(all);
	all = NULL;
}
