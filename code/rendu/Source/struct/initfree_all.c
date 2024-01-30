/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:06:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/30 23:24:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	init_minishell_signal(int *mss)
{
	(*mss) = 0;
}

int	init_all(t_all_struct **res, char **env)
{
	if (!res)
		return (1);
	(*res) = ft_calloc(1, sizeof(t_all_struct));
	if (!res)
		return (1);
	(*res)->err = init_all_va(&(*res)->all_va, env);
	(*res)->err = init_prompt(&(*res)->prompte);
	(*res)->exe = NULL;
	(*res)->cmdpath = NULL;
	(*res)->status = 0;
	(*res)->env = NULL;
	update_env(res);
	return ((*res)->err);
}

void	free_all(t_all_struct *all)
{
	if (!all)
		return ;
	free_execute(all->exe);
	free_prompt(all->prompte);
	free_all_va(all->all_va);
	free_tab(&(all->env));
	free(all);
	all = NULL;
}
