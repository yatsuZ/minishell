/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:18:03 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/08 03:05:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

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

char	*get_value(t_env *all_va, char *key, int status, int *err)
{
	char	*value;

	value = NULL;
	if (*err == 0 && ft_strcpm(key, "?") == TRUE)
		value = int_to_str(status, err);
	while (*err == 0 && all_va && !value)
	{
		if (ft_strcpm(all_va->key, key) == TRUE)
			value = ft_strdup(all_va->value, err);
		all_va = all_va->next_va;
	}
	return (value);
}

void	str_change_env(char **str, t_env *all_env, int status, int *err)
{
	t_node	*n;
	t_node	*tmp;

	n = NULL;
	if (*err || !str || !(*str) || str_to_node(*str, &n, err))
		return ;
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
		fusion_node(n, NON_DEFINI, err);
	free_2str(str, NULL);
	if (*err == 0)
		*str = ft_strdup(n->str, err);
	free_all_node(n);
}

t_env	*add_key_value(char *key, char *value, int show, int *err)
{
	t_env	*res;

	if (*err)
		return (NULL);
	res = ft_calloc(1, sizeof(t_env));
	if (!res)
		return (*err = 1, NULL);
	res->key = ft_strdup(key, err);
	res->value = ft_strdup(value, err);
	res->show = FALSE;
	if (show)
		res->show = TRUE;
	res->next_va = NULL;
	return (res);
}

int	change_or_add_va(t_env **all_env, char *key, char *value, int show)
{
	int	err;

	err = 0;
	if (!all_env || *all_env == NULL)
	{
		if (all_env)
			*all_env = add_key_value(key, value, show, &err);
		return (err);
	}
	while ((*all_env)->next_va)
	{
		if (ft_strcpm(key, (*all_env)->key) == TRUE)
			return (free_2str(&((*all_env)->value), NULL), \
(*all_env)->value = ft_strdup(value, &err), (*all_env)->show = show, err);
		all_env = &((*all_env)->next_va);
	}
	if (ft_strcpm(key, (*all_env)->key) == TRUE)
	{
		free_2str(&((*all_env)->value), NULL);
		(*all_env)->value = ft_strdup(value, &err);
		(*all_env)->show = show;
	}
	else
		(*all_env)->next_va = add_key_value(key, value, show, &err);
	return (err);
}
