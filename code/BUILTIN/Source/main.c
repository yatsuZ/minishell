/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/19 16:50:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	g_status;

void	reset_var(t_all_struct *all)
{
	if (!all)
		return ;
	free(all->prompte->brut);
	all->prompte->brut = NULL;
	free_all_node(all->prompte->all_cmd_line);
	all->prompte->all_cmd_line = NULL;
	free_execute(all->exe);
	all->exe = NULL;
}

void	ft_minishell(t_all_struct *all)
{
	int	iderr;

	g_status = 0;
	while (all)
	{
		iderr = parsing(all);
		if (all->prompte->brut == NULL)
			end(all);
		if (iderr)
			error_parsing(iderr);
		// show_prompt(all->prompte);
		add_history(all->prompte->brut);
		prompte_to_execute(all);
		// show_execute(all->exe, 0);
		if (all && all->exe)
			g_status = ft_exec(all->exe, &all);
		reset_var(all);
	}
}
//EXECUTE

int	main(int ac, char **av, char **env)
{
	t_all_struct	*all;

	(void) ac;
	(void) av;
	if (init_all(&all, env))
		end(all);
	ft_minishell(all);
	end(all);
}