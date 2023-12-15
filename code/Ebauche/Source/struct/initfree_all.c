/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:06:47 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 12:46:02 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_all(t_all_struct **res)
{
	if (ft_calloc_verif(1, sizeof(t_all_struct), (void **)res))
		return (1);
	if (init_prompt((*res)->prompte))
		return (1);
	(*res)->err = 0;
	return (0);
}

void	free_all(t_all_struct *all)
{
	
}

