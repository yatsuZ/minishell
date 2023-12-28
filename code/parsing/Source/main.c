/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 15:47:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	ft_minishell(t_all_struct *all)
{
	int	tour;
	int	iderr;

	tour = 3;
	while (tour--)
	{
		iderr = parsing(all);
		show_prompt(all->prompte);
		if (iderr)
			error_parsing(iderr);
		add_history(all->prompte->brut);
		free(all->prompte->brut);
		all->prompte->brut = NULL;
		free_all_node(all->prompte->all_cmd_line);
		all->prompte->all_cmd_line = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	(void)	ac;
	(void)	av;
	t_all_struct	*all;

	if (init_all(&all, env))
		end(all);
	show_all_va(all->all_va);
	// ft_minishell(all);
	end(all);
}
