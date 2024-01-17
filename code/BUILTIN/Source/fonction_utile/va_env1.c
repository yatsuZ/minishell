/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:18:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/17 11:48:38 by yzaoui           ###   ########.fr       */
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
		if (type_of_str(s[i]) >= 0 || s[i] == '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	*get_value(t_env *all_va, char *key)
{
	char	*value;

	value = NULL;
	if (ft_strcpm(key, "?") == TRUE)
		value = int_to_str(STATUS);
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

void	str_change_env(char **str, t_env *all_env)
{
	t_node	*n;
	t_node	*tmp;

	if (!str || !(*str))
		return ;
	n = NULL;
	str_to_node(*str, &n);
	tmp = n;
	while (tmp)
	{
		if (tmp->str[0] == '$')
			tmp->type_input = VA_ENV;
		tmp = tmp->next_node;
	}
	tmp = NULL;
	fusion_va(all_env, n, NULL);
	while (n && n->next_node)
		fusion_node(n, NON_DEFINI);
	free(*str);
	*str = NULL;
	*str = ft_strdup(n->str);
	free_all_node(n);
}
