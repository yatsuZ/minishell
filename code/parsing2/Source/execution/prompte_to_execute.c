/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompte_to_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:00:12 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/05 04:50:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_execute	*init_execute(char *cmd, char **arg, t_redirection *rd, int *err)


t_execute	*get_all_exe(t_prompt *p, t_node *n, size_t i)
{
	t_execute	*res;
	
	if (!n)
		return (NULL);
	
}

void	prompte_to_execute(t_all_struct *all)
{
	all->exe = get_all_exe(all->prompte, all->prompte->all_cmd_line, 0);
}