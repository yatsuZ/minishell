/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:57:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 09:59:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static char	*all_va_to_char_for_export(t_env *all_va)
{
	char	*str;
	char	*next_str;

	if (!all_va)
		return (ft_strdup(""));
	str = ft_strdup("export ");
	str_add(&str, all_va->key, 0);
	str_add(&str, "=\"", 0);
	str_add(&str, all_va->value, 0);
	str_add(&str, "\"\n", 0);
	next_str = all_va_to_char_for_export(all_va->next_va);
	if (!next_str)
		return (str);
	str_add(&str, next_str, 1);
	next_str = NULL;
	return (str);
}

static char	*get_value_from_str(char *str, size_t start)
{
	size_t	stop;

	stop = start + 1;
	while (str[stop])
		stop++;
	return (ft_strcut(str, start, stop));
}

int	ft_export(char *str, t_env **all_env)
{
	char	*key;
	char	*value;
	size_t	stop;

	stop = 0;
	while (str && str[stop] && str[stop] != '=')
		stop++;
	key = ft_strcut(str, 0, stop);
	if (is_a_legit_va_env(key) == FALSE)
	{
		print_fd("Minishelle : export: `", 2);
		print_fd(key, 2);
		print_fd("\': key non valide\n", 2);
		return (free_2str(&key, NULL), value = NULL, 1);
	}
	if (str[stop] == '\0' || str[stop + 1] == '\0')
		value = ft_strdup("");
	else
		value = get_value_from_str(key, stop + 1);
	return (change_or_add_va(all_env, key, value), free_2str(&key, &value), 0);
}

int	exec_export(t_execute *exe, t_all_struct **all)
{
	char	*msg;
	int		status;
	size_t	i;

	i = 0;
	status = 0;
	if (exe->arg == NULL)
	{
		msg = all_va_to_char_for_export((*all)->all_va);
		printf("%s", msg);
		return (free_2str(&msg, NULL), status);
	}
	while (exe->arg[i])
	{
		if (ft_export(exe->arg[i], &(*all)->all_va))
			status = 1;
		i++;
	}
	return (status);
}
