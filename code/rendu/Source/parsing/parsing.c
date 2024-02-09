/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:52:43 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 14:33:00 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	cut_new_space(t_node **tete, t_node *prev, int *err)
{
	if (*err || !(*tete))
		return ;
	if ((*tete)->type_input != NON_DEFINI)
		return (cut_new_space(&((*tete)->next_node), (*tete), err));
	prev = no_define_to_node(tete, &prev, err);
	cut_new_space(&(prev->next_node), prev, err);
}

static int	parsing2(t_all_struct *all)
{
	fusion_va(all->all_va, all->prompte->all_cmd_line, NULL, all->status);
	find_cmd_and_arg(all->prompte->all_cmd_line, NULL, 0, &(all->err));
	if (all->err)
		return (all->err = 1, end(all), 1);
	index_update(all->prompte->all_cmd_line);
	return (0);
}

int	parsing(t_all_struct *all)
{
	int	err_parsing;

	all->prompte->brut = readline(all->prompte->invite);
	if (all->prompte->brut == NULL)
		end(all);
	if (have_nwl(all->prompte->brut, 0))
		return (err_parsing = 8, err_parsing);
	if (str_to_node(all->prompte->brut, \
	&(all->prompte->all_cmd_line), &(all->err)))
		return (all->err = 1, end(all), 1);
	err_parsing = find_cote_and_va(all->prompte->all_cmd_line, NON_DEFINI);
	if (err_parsing)
		return (err_parsing);
	fusion_cote(all->prompte->all_cmd_line, &(all->err));
	if (all->err)
		return (all->err = 1, end(all), 1);
	err_parsing = find_all_rd_and_pip(all->prompte, &(all->err));
	if (all->err)
		return (all->err = 1, end(all), 1);
	if (err_parsing)
		return (err_parsing);
	return (parsing2(all));
}
