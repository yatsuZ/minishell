/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 10:31:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_env	*del_va(char *key, t_env *env)
{
	t_env	*new_va_next;

	if (!env)
		return (env);
	if (ft_strcpm(key, env->key))
	{
		new_va_next = env->next_va;
		free_env(&env);
		return (new_va_next);
	}
	env->next_va = del_va(key, env->next_va);
	return (env);
}

int	exec_unset(t_execute *exe, t_all_struct **all)
{
	size_t	i;

	(void) all;
	i = 0;
	while (exe->arg && exe->arg[i])
		(*all)->all_va = del_va(exe->arg[i++], (*all)->all_va);
	return (0);
}
