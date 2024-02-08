/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:15:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/07 08:53:52 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

void	change_va_undescore(t_execute *exe, t_env **env)
{
	char	*new_end;
	size_t	i;

	if (!exe || ft_strcpm(exe->cmd, "exit"))
		return ;
	new_end = NULL;
	i = exe->argc;
	while (exe->arg && i && !new_end)
	{
		new_end = exe->arg[i];
		i--;
	}
	if (new_end == NULL)
		new_end = exe->cmd;
	change_or_add_va(env, "_", new_end, 0);
}

void	update_shlvl(t_env *tete, int err, long long shlvl)
{
	char		*nbr_str;
	char		*str;

	str = get_value(tete, "SHLVL", 0);
	shlvl = is_numeric2(str, 0, &err);
	free_2str(&str, NULL);
	if (shlvl >= 999)
		print_fd("minishell: warning shell leave too high, reset at 1\n", 2);
	if (shlvl >= 999 || err)
		change_or_add_va(&tete, "SHLVL", "1", 1);
	else if (shlvl < 0)
		change_or_add_va(&tete, "SHLVL", "0", 1);
	else
	{
		nbr_str = int_to_str((int)(shlvl + 1));
		change_or_add_va(&tete, "SHLVL", nbr_str, 1);
		free_2str(&nbr_str, NULL);
	}
}
