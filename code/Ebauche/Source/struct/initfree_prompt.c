/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:56:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 12:49:21 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_prompt(t_prompt *promp)
{
	if (ft_calloc_verif(1, sizeof(t_prompt), (void **)&promp))
		return (1);
	promp->invite = "$>";
	promp->end_of_prompt = false;
}

int	free_prompt(t_prompt *promp)
{
	
}

