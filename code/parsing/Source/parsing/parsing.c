/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:52:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/23 22:38:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

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

	err_parsing = first_parsing(all);
	return (err_parsing);
}
