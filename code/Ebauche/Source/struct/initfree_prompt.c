/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:56:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/23 22:27:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_prompt(t_prompt **promp)
{
	if (ft_calloc_verif(1, sizeof(t_prompt), (void **)promp))
		return (1);
	(*promp)->invite = ft_strdup("$>");
	(*promp)->err_parsing = 0;
	(*promp)->all_cmd_line = NULL;
	return (0);
}

void	free_prompt(t_prompt *promp)
{
	if (!promp)
		return ;
	free(promp->invite);
	free(promp);
	promp = NULL;
}
