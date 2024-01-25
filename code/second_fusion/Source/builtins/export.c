/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:57:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/25 02:57:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	print_env_export(t_env *all_va)
{
	printf("CHEF\n");
	if (!all_va)
		return ;
	if (all_va->show)
	{
		if (all_va->value)
			printf("export %s=\"%s\"\n", all_va->key, all_va->value);
		else
			printf("export %s\n", all_va->key);
	}
	print_env_export(all_va->next_va);
}

static char	*get_value_from_str(char *str, size_t stop)
{
	char	*res;
	size_t	start;

	start = stop + 1;
	while (str[stop])
		stop++;
	res = ft_strcut(str, start, stop);
	return (res);
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
	if (is_a_legit_va_env(key) == FALSE || ft_strcpm("?", key) == TRUE)
	{
		print_fd("Minishelle : export: `", 2);
		if (key)
			print_fd(key, 2);
		print_fd("\': key non valide\n", 2);
		return (free_2str(&key, NULL), value = NULL, 1);
	}
	if (str[stop] == '\0' || str[stop + 1] == '\0')
		value = ft_strdup("");
	else
		value = get_value_from_str(str, stop);
	return (change_or_add_va(all_env, key, value, 1), free_2str(&key, &value), 0);
}

int	exec_export(t_execute *exe, t_all_struct **all)
{
	int		status;
	size_t	i;

	i = 0;
	status = 0;
	if (exe->nbr_arg == 0)
		return (print_env_export((*all)->all_va), status);
	while (i < exe->nbr_arg)
	{
		if (ft_export(exe->arg[i], &(*all)->all_va))
			status = 1;
		i++;
	}
	return (status);
}
