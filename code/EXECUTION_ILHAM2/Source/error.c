/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:22:45 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 09:48:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	show_error(t_all_struct *all)
{
	if (!all || all->err == 1)
		return (perror("Malloc faillure. "), -1);
	return (status);
}

void	end(t_all_struct *all)
{
	status = show_error(all);
	free_all(all);
	clear_history();
	exit(status);
}
