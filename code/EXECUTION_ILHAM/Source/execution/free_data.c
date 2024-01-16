/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:37 by ilham_oua         #+#    #+#             */
/*   Updated: 2024/01/11 16:08:06 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

void	free_all_data(t_data *data, int code, int code2)
{
	if (code2 < 4)
		perror("");
	if (code2 > 0)
		free_tab(data->env);
	if (code2 > 1)
		free_tab(data->cmds);
	if (code2 > 2)
		free(data->pids);
	exit(code);
}
