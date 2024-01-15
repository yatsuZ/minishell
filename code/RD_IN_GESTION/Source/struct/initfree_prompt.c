/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:56:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 18:51:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_prompt(t_prompt **promp)
{
	if (ft_calloc_verif(1, sizeof(t_prompt), (void **)promp))
		return (1);
	(*promp)->invite = ft_strdup("$>");
	(*promp)->brut = NULL;
	(*promp)->err_parsing = 0;
	(*promp)->all_cmd_line = NULL;
	(*promp)->nbr_of_pip = 0;
	(*promp)->nbr_of_rd = 0;
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
