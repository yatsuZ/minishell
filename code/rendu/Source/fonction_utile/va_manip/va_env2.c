/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:15:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 15:00:01 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

int	change_va_undescore(t_execute *exe, t_env **env)
{
	char	*new_end;
	size_t	i;

	if (!exe || ft_strcpm(exe->cmd, "exit"))
		return (0);
	new_end = NULL;
	i = exe->argc;
	while (exe->arg && i && !new_end)
	{
		new_end = exe->arg[i];
		i--;
	}
	if (new_end == NULL)
		new_end = exe->cmd;
	return (change_or_add_va(env, "_", new_end, 0));
}

int	update_shlvl(t_env *tete, int err, long long shlvl)
{
	int			err_malloc;
	char		*nbr_str;
	char		*str;

	err_malloc = 0;
	str = get_value(tete, "SHLVL", 0, &err_malloc);
	if (err_malloc)
		return (1);
	shlvl = is_numeric2(str, 0, &err);
	free_2str(&str, NULL);
	if (shlvl >= 999)
		print_fd("minishell: warning shell leve too high, reset at 1\n", 2);
	if (shlvl >= 999 || err)
		err_malloc = change_or_add_va(&tete, "SHLVL", "1", 1);
	else if (shlvl < 0)
		err_malloc = change_or_add_va(&tete, "SHLVL", "0", 1);
	else
	{
		nbr_str = int_to_str((int)(shlvl + 1), &err_malloc);
		if (err_malloc)
			return (1);
		err_malloc = change_or_add_va(&tete, "SHLVL", nbr_str, 1);
		free_2str(&nbr_str, NULL);
	}
	return (err_malloc);
}

int	fail_key2(t_env *all_va, t_node *mtn, int status)
{
	int	err;

	err = 0;
	if (mtn->next_node && (mtn->next_node->type_input == STR || \
	mtn->next_node->type_input == NON_DEFINI))
		fusion_node(mtn, -1, &err);
	if (err)
		return (err);
	if (mtn->next_node && (mtn->next_node->type_input == STR || \
	mtn->next_node->type_input == NON_DEFINI))
		fusion_node(mtn, -1, &err);
	if (err)
		return (err);
	return (fusion_va(all_va, mtn->next_node, mtn, status));
}
