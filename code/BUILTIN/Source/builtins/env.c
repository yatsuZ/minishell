/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:30 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 09:08:46 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static char	*all_va_to_char(t_env *all_va)
{
	char	*str;
	char	*next_str;

	if (!all_va)
		return (ft_strdup(""));
	str = ft_strjoin(all_va->key, "=");
	str_add(&str, all_va->value, 0);
	next_str = all_va_to_char(all_va->next_va);
	str_add(&str, "\n", 0);
	if (!next_str)
		return (str);
	str_add(&str, next_str, 1);
	next_str = NULL;
	return (str);
}

int	exec_env(t_execute *exe, t_all_struct **all)
{
	char	*env;

	(void) exe;
	env = all_va_to_char((*all)->all_va);
	printf("%s", env);
	free_2str(&env, NULL);
	return (0);
}
