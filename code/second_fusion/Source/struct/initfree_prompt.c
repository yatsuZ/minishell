/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfree_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:56:25 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 16:19:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	init_prompt(t_prompt **promp)
{
	if (!promp)
		return (1);
	*promp = ft_calloc(1, sizeof(t_prompt));
	if (!(*promp))
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
	free_all_node(promp->all_cmd_line);
	promp->all_cmd_line = NULL;
	free(promp->invite);
	promp->invite = NULL;
	free(promp);
	promp = NULL;
}
