/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:18:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/14 19:05:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	is_a_legit_va_env(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (type_of_str(s[i]) >= 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*get_exit_status(void)
{
	return (ft_strdup("Jai pas encore fais les signal -_-.\n"));
}

char	*get_value(t_env *all_va, char *key)
{
	char	*value;

	value = NULL;
	if (ft_strcpm(key, "?") == TRUE)
		value = get_exit_status();
	while (all_va && !value)
	{
		if (ft_strcpm(all_va->key, key) == TRUE)
			value = ft_strdup(all_va->value);
		all_va = all_va->next_va;
	}
	if (!value)
		value = ft_strdup("");
	return (value);
}
