/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:52:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/03 01:54:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	cut_new_space(t_node **tete, t_node *prev)
{
	if (!(*tete))
		return ;
	if ((*tete)->type_input != NON_DEFINI)
		return (cut_new_space(&((*tete)->next_node), (*tete)));
	prev = no_define_to_node(tete, &prev);
	cut_new_space(&(prev->next_node), prev);
}

int	parsing(t_all_struct *all)
{
	int	err_parsing;

	all->prompte->brut = readline(all->prompte->invite);
	str_to_node(all->prompte->brut, &(all->prompte->all_cmd_line));
	err_parsing = find_cote_and_va(all->prompte->all_cmd_line, NON_DEFINI);
	if (err_parsing)
		return (err_parsing);
	fusion_cote(all->prompte->all_cmd_line);
	err_parsing = find_all_rd_and_pip(all->prompte);
	if (err_parsing)
		return (err_parsing);
	fusion_va(all->all_va, all->prompte->all_cmd_line, NULL);
	find_cmd_and_arg(all->prompte->all_cmd_line, NULL, 0);
	index_update(all->prompte->all_cmd_line);
	return (err_parsing);
}
