/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:57:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 10:28:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

int	exec_export(t_execute *exe, t_all_struct **all)
{
	(void) all;
	show_execute(exe, 0);
	printf("Je dois faire la commande export\n");
	return (0);
}
