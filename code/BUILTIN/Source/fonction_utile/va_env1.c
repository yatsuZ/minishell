/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:18:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/19 18:09:14 by yzaoui           ###   ########.fr       */
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
		value = int_to_str(g_status);
	while (all_va && !value)
	{
		if (ft_strcpm(all_va->key, key) == TRUE)
			value = ft_strdup(all_va->value);
		all_va = all_va->next_va;
	}
	if (!value)
		value = NULL;
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

t_env	*add_key_value(char *key, char *value)
{
	t_env	*res;

	res = ft_calloc(1, sizeof(t_env));
	res->key = ft_strdup(key);
	res->value = ft_strdup(value);
	res->next_va = NULL;
	return (res);
}

int	change_or_add_va(t_env *all_env, char *key, char *value)
{
	while (all_env)
	{
		if (ft_strcpm(all_env->key, key) == TRUE)
		{
			free(all_env->value);
			all_env->value = NULL;
			all_env->value = ft_strdup(value);
			return (0);
		}
		all_env = all_env->next_va;
	}
	all_env = add_key_value(key, value);
	return (0);
}
