/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:30 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 10:28:35 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

int	exec_env(t_execute *exe, t_all_struct **all)
{
	(void) all;
	show_execute(exe, 0);
	printf("Je dois faire la commande env\n");
	return (0);
}
