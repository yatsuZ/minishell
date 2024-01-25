/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:36:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/25 02:46:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	free_env(t_env **env)
{
	if (!env)
		return ;
	free_2str(&((*env)->key), &((*env)->value));
	(*env)->next_va = NULL;
	free(*env);
	(*env) = NULL;
}

static void	compare(char *str, int *nbr, t_env **env, int err)
{
	long long	shlvl;
	char		*nbr_str;

	if (ft_strcpm("OLDPWD", str) == TRUE)
		(*nbr) = (*nbr) - 8;
	else if (ft_strcpm("PWD", str) == TRUE)
		(*nbr) = (*nbr) - 4;
	else if (ft_strcpm("SHLVL", str) == TRUE)
	{
		(*nbr) = (*nbr) - 2;
		err = 0;
		shlvl = is_numeric2(str, 0, &err);
		if (shlvl < -1000 || shlvl == 999 || err)
			change_or_add_va(env, "SHLVL", "1", 1);
		else if (shlvl < 0)
			change_or_add_va(env, "SHLVL", "0", 1);
		else
		{
			nbr_str = int_to_str((int) (shlvl + 1));
			change_or_add_va(env, "SHLVL", nbr_str, 1);
			free(nbr_str);
		}
	}
	else if (ft_strcpm("_", str) == TRUE)
		(*nbr) = (*nbr) - 1;
}

t_env	*init_va_required(t_env *tete, t_env *i)
{
	int	option;

	option = 15;
	while (i)
	{
		compare(i->key, &option, &tete, 0);
		i = i->next_va;
	}
	if (option >= 8)
	{
		printf("N = %d\n", option);
		change_or_add_va(&tete, "OLDPWD", NULL, 1);
		option = option - 8;
	}
	else if (option >= 4)
	{
		change_or_add_va(&tete, "PWD", getcwd(NULL, 0), 1);
		option = option - 4;
	}
	else if (option >= 2)
	{
		change_or_add_va(&tete, "SHLVL", "1", 1);
		option = option - 2;
	}
	else if (option)
		change_or_add_va(&tete, "_", "minishell ;)", 0);
	return (tete);
}
