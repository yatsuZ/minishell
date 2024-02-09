/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 10:08:51 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	g_exit_signal = 0;

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
		init_signal(SHE, IGN);
		iderr = parsing(all);
		if (all->prompte->brut[0])
			add_history(all->prompte->brut);
		if (iderr)
			error_parsing(iderr);
		else
		{
			prompte_to_execute(all);
			if (all && all->exe)
				all->status = execute(&all);
		}
		reset_var(all);
	}
}

int	main(int ac, char **av, char **env)
{
	t_all_struct	*all;

	(void) av;
	if (ac == 1)
	{
		if (init_all(&all, env))
			end(all);
		ft_minishell(all);
		end(all);
	}
	else
		printf("error, too much arguments\n");
	return (0);
}
