/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/18 00:51:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	ft_minishell(t_all_struct *all)
{
	all->err = get_invite_de_comande(all->prompte);
	if (all->err)
		return ;
	show_prompt(all->prompte);
	free_all_node(all->prompte->all_cmd_line);
}

int	main(void)
{
	t_all_struct	*all;

	if (init_all(&all))
		end(all);
	ft_minishell(all);
	end(all);
}
