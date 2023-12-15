/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:22:45 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 01:06:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	end(t_all_struct *all)
{
	if (!all || all->err == 1)
		return (perror("Malloc faillure."), free_all(all), 1);
	return (free_all(all), 0);
}
