/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:52:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 21:06:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_execute	*prompt_to_execute(t_all_struct *all)
{
	if (!all)
		return (NULL);
	return (NULL);
}

void	fusion_va(t_all_struct *all)
{
	if (!all)
		return ;
}

// Fonction qui va permertre de defnir quelle sont les type d'inpute
// Verifier les cote puis double cote entre les deux c'est des string
// Verifier les variable global
// puis modifie la structure node par consequent + verfie la syntax
// Verifier les pip + le nombre de pip
// Verifier les redirection
// puis modifie la structure node par consequent + verfie la syntax
// Modifier les variable global et modifier les str 
// (refaire un decoupage en gros) Verifier les cmd
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
	fusion_va(all);
	// find_cmd_and_arg(all);
	return (err_parsing);
}

// Je dois cree un strcuture qui recupere 
// l'environement et couper la string de l'env quavec les separateur