/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 16:02:48 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	reset_var(t_all_struct *all)
{
	free(all->prompte->brut);
	all->prompte->brut = NULL;
	free_all_node(all->prompte->all_cmd_line);
	all->prompte->all_cmd_line = NULL;
	free_execute(all->exe);
	all->exe = NULL;
}

void	ft_minishell(t_all_struct *all)
{
	int	tour;
	int	iderr;

	tour = 1;
	while (tour--)
	{
		iderr = parsing(all);
		if (iderr)
			error_parsing(iderr);
		prompte_to_execute(all);
		// show_prompt(all->prompte);
		show_execute(all->exe, 0);
		add_history(all->prompte->brut);
		//EXECUTE
		execute(all);
		reset_var(all);
	}
}

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
