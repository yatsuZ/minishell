/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/31 13:29:40 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	g_signal;

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

	while (all)
	{
		iderr = parsing(all);
		add_history(all->prompte->brut);
		// show_prompt(all->prompte);
		if (iderr)
			error_parsing(iderr);
		else
		{
			prompte_to_execute(all);
			if (all && all->exe)
				all->status = execute(&all);
				// all->status = ft_all_exec(all->exe, &all);
			// show_execute(all->exe, 0);
		}
		reset_var(all);
	}
}
//EXECUTE

int	main(int ac, char **av, char **env)
{
	t_all_struct	*all;

	(void) ac;
	(void) av;
	g_signal = 0;
	if (init_all(&all, env))
		end(all);
	ft_minishell(all);
	end(all);
}
