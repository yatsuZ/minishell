/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite_de_comande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:13:16 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/11 00:45:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"


void	get_invite_de_comande(void)
{
	char	*input;
	int		its_exit;

	its_exit = 1;
	while (its_exit)
	{
		input = readline("$>");
		printf("Vous avez ecris : %s\n", input);
		if (!input || ft_strcpm(input, "exit"))
			its_exit = 0;
		free(input);
		input = NULL;
	}
	clear_history();
}
