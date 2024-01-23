/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:18:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 20:25:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	is_a_legit_va_env(char *s)
{
	size_t	i;

	i = 0;
	if (!s || (s[0] >= '0' && s[0] <= '9'))
		return (FALSE);
	while (s[i])
	{
		if (type_of_str(s[i]) >= 0 || s[i] == '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	*get_value(t_env *all_va, char *key, int status)
{
	char	*value;

	value = NULL;
	if (ft_strcpm(key, "?") == TRUE)
		value = int_to_str(status);
	while (all_va && !value)
	{
		if (ft_strcpm(all_va->key, key) == TRUE)
			value = ft_strdup(all_va->value);
		all_va = all_va->next_va;
	}
	return (value);
}

void	str_change_env(char **str, t_env *all_env, int status)
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
	fusion_va(all_env, n, NULL, status);
	while (n && n->next_node)
		fusion_node(n, NON_DEFINI);
	free(*str);
	*str = NULL;
	if (!n)
		*str = NULL;
	else
		*str = ft_strdup(n->str);
	free_all_node(n);
}

t_env	*add_key_value(char *key, char *value)
{
	t_env	*res;

	res = ft_calloc(1, sizeof(t_env));
	res->key = ft_strdup(key);
	if (!value)
		res->value = NULL;
	else
		res->value = ft_strdup(value);
	res->next_va = NULL;
	return (res);
}

t_env	**change_or_add_va(t_env **all_env, char *key, char *value)
{
	if (*all_env == NULL)
	{
		*all_env = add_key_value(key, value);
		return (all_env);
	}
	else if ((*all_env)->next_va == NULL)
	{
		*all_env = add_key_value(key, value);
		return (all_env);
	}
	else if (ft_strcpm(key, (*all_env)->key) == TRUE)
	{
		free_2str(&((*all_env)->value), NULL);
		(*all_env)->value = ft_strdup(value);
		return (all_env);
	}
	(*all_env)->next_va = change_or_add_va(&(*all_env)->next_va, key, value);
	return (all_env);
}
