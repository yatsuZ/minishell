/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:01 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 13:09:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

// Faire un get prompte qui recupere tout le prompte de la meme maniere que geat next line. 

void	ft_minishell(t_all_struct *all)
{
	free(all);
}

int	main(void)
{
	t_all_struct	*all;

	if (init_all(&all))
		printf("ERROR à l'init.\n");
	init_node(&(all->prompte->all_cmd_line), ft_strdup("ls -a"));
	add_node(all->prompte->all_cmd_line, ft_strdup("|"));
	add_node(all->prompte->all_cmd_line->next_node, ft_strdup("grep a"));
	printf("prompte->invite = %s\n", all->prompte->invite);
	printf("prompte->1NODE = %s\n", all->prompte->all_cmd_line->str);
	printf("prompte->2NODE = %s\n", all->prompte->all_cmd_line->next_node->str);
	printf("prompte->3NODE = %s\n", all->prompte->all_cmd_line->next_node->next_node->str);
	printf("prompte->4NODE = %p\n", all->prompte->all_cmd_line->next_node->next_node->next_node);
	free_all(all);
	return (0);
	// ft_minishell(all);
	// return (free_all(all));
}
