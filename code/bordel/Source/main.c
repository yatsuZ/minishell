/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/12 22:08:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere tout le prompte de la meme maniere que geat next line. 

void	ft_minishell(t_all_struct *all)
{


}

int	main(void)
{
	t_all_struct	*all;

	if (init_all(&all))
		return (free_all(all));
	ft_minishell(all);
	return (free_all(all));
}
