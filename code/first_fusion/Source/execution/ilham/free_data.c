/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:37 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/22 18:41:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	if (table == NULL)
		return ;
	while (table[i])
	{
		free (table[i]);
		i++;
	}
	free (table);
}

void	free_all_data(t_all_struct *all, int code2)
{
	if (code2 < 4)
		perror("");
	if (code2 > 0)
		free_table(all->env);
	if (code2 > 1)
		// perror("free cmds table");//free_table(all->exe->cmds);
	if (code2 > 2)
		free(all->pids);
}
