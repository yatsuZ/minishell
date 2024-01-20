/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:22:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/20 18:20:04 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	show_error(t_all_struct *all)
{
	if (!all || all->err == 1)
		return (print_fd("Malloc faillure.\n", 2), -1);
	return (g_status);
}

void	end(t_all_struct *all)
{
	g_status = show_error(all);
	free_all(all);
	clear_history();
	exit(g_status);
}
