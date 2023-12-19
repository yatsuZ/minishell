/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/19 01:46:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

void	init_minishell_signal()
{
	minishell_signal = 0;
	// redefinir ctrl+d,+c,+/
}

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	ft_minishell(t_all_struct *all)
{
	int	tour;

	tour = 2;
	while (tour--)
	{
		all->err = get_invite_de_comande(all->prompte);
		if (all->err)
			return ;
		show_prompt(all->prompte);
		free_all_node(all->prompte->all_cmd_line);
		all->prompte->all_cmd_line = NULL;
	}
}

int	main(void)
{
	t_all_struct	*all;
	static int		minishell_signal;

	init_minishell_signal();// A FAIRE
	if (init_all(&all))
		end(all);
	ft_minishell(all);
	end(all);
}
