/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:36:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 10:32:55 by yzaoui           ###   ########.fr       */
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
