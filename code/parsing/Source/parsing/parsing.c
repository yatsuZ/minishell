/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:52:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:08:28 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

t_execute	*prompt_to_execute(t_all_struct *all)
{
	if (!all)
		return (NULL);
	return (NULL);
}

void	fusion_cote(t_all_struct *all)
{
	if (!all)
		return ;
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

	err_parsing = find_cote_and_va(all->prompte->all_cmd_line, NON_DEFINI);
	if (err_parsing)
		return (err_parsing);
	// fusion_cote(all);
	// fusion_va(all);
	// err_parsing = find_all_rd_and_pip(all);
	// if (err_parsing)
	// 	return (err_parsing);
	// err_parsing = first_parsing(all);
	return (err_parsing);
}
