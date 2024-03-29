/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:30 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/26 23:39:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	print_env(t_env *all_va)
{
	if (!all_va)
		return ;
	if (all_va->show && all_va->value)
		printf("%s=%s\n", all_va->key, all_va->value);
	print_env(all_va->next_va);
}

int	exec_env(t_execute *exe, t_all_struct **all)
{
	(void) exe;
	print_env((*all)->all_va);
	printf("_=bultin de minishell\n");
	return (0);
}
