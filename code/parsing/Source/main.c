/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/25 23:05:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere 
// tout le prompte de la meme maniere que geat next line.

void	ft_minishell(t_all_struct *all)
{
	int	tour;
	int	error_parsing;

	tour = 2;
	while (tour--)
	{
		all->err = get_all_input(all->prompte);
		if (all->err)
			return ;
		error_parsing = parsing(all);
		show_prompt(all->prompte);
		if (error_parsing)
			printf("Il y a une erreur dans le parsing.\n");
		free_all_node(all->prompte->all_cmd_line);
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
