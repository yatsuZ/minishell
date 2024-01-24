/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:36:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/24 20:29:54 by yzaoui           ###   ########.fr       */
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

void	init_va_required(t_env **env)
{
	int	shlvl_present;// shlvl = + 1 pour shlvl ou egale a 1 si null/ vide ou + ou = a 999 | est egale a 0 siest egale a 0 et/ou negativ (10 numa la suite)
	int	pwd_present;// faire PWD et OLDPWD avec si on les affiche ou non
	int	oldpwd_present;
	int	underscore_present;// la va _ et egale aucdernier cmd ou arg commande sauf exit=ne modefie pas. concernant laffichage lors de env on affiche la cmd et export rien donc par defaux _ on ne laffiche jammais, si la clée est _ alors la value est gale a tout
	if (!all_env)
		return ;
	if (*all_env == NULL)
	{
		*all_env = add_key_value(key, value);
		return ;
	}
	while ((*all_env)->next_va)
	{
		if (ft_strcpm(key, (*all_env)->key) == TRUE)
		{
			free_2str(&((*all_env)->value), NULL);
			(*all_env)->value = ft_strdup(value);
			return ;
		}
		all_env = &((*all_env)->next_va);
	}
	if (ft_strcpm(key, (*all_env)->key) == TRUE)
	{
		free_2str(&((*all_env)->value), NULL);
		(*all_env)->value = ft_strdup(value);
	}
	else
		(*all_env)->next_va = add_key_value(key, value);


}
