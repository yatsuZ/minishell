/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:44:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	ft_minishell(t_all_struct *all)
{
	int	tour;
	int	iderr;

	tour = 2;
	while (tour--)
	{
		all->err = get_all_input(all->prompte);
		if (all->err)
			return ;
		iderr = parsing(all);
		show_prompt(all->prompte);
		if (iderr)
			error_parsing(iderr);
		else
			add_history(all->prompte->brut);
		free_all_node(all->prompte->all_cmd_line);
		free(all->prompte->brut);
		all->prompte->brut = NULL;
		all->prompte->all_cmd_line = NULL;
	}
}

int	main(void)
{
	t_all_struct	*all;

	if (init_all(&all))
		end(all);
	ft_minishell(all);
	end(all);
}
