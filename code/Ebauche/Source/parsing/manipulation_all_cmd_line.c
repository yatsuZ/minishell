/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation_all_cmd_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 15:34:50 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/25 18:21:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// Fusion de VA_ENV en de hors de cote donc si sa echoue == NON_INDEFINI
// doit fusione avec le noeud suivant si lenoeud suivant et legit sinon change
// le type du noeud actuel par le parametre et return 1 en cas dechec
int	fusion_va_env(t_node *n, int new_type_if_fail)
{
	if (n->next_node == NULL || is_a_legit_va_env(n->next_node->str) == FALSE)
	{
		n->type_input = new_type_if_fail;
		return (1);
	}
	if (strcmp(n->next_node->str, "?") == TRUE)
		fusion_node(n, VA_RETOUR);
	else
		fusion_node(n, VA_ENV);
	return (0);
}

int	fusion_single_cote(t_node *n)
{
	n = n->next_node;
	if (n == NULL)
		return (1);
	while (n->next_node && n->type_input != SINGLE_COTE)
		fusion_node(n, -1);
	if (n->next_node == NULL && n->type_input != SINGLE_COTE)
		return (1);
	return (0);
}

int	fusion_double_cote(t_node *n)
{
	n = n->next_node;
	if (n == NULL)
		return (1);
	while (n->next_node && n->type_input != DOUBLE_COTE)
	{
		if (n)
		fusion_node(n, -1);
	}
	if (n->next_node == NULL && n->type_input != DOUBLE_COTE)
		return (1);
	return (0);
}

// fonction qui permet de fusioner les string double et simple cote et VA_ENV 
// si legit
// return 1 si il y a une erreur de syntax si les cote ne se referme pas.
int	fusion_str_and_env(t_node *tete)
{
	if (!tete)
		return (0);
	else if (tete->type_input == VA_ENV)
		fusion_va_env(tete, NON_DEFINI);// NON JE DOIS changer sa car je dois dabors modifier les string puis verfier la va denvironement une string peut etre une va
	// else if (tete->type_input == SINGLE_COTE)
	// {
	// 	if (fusion_single_cote(tete))
	// 		return (1);
	// 	tete = tete->next_node;
	// }
	// else if (tete->type_input == DOUBLE_COTE)
	// {
	// 	if (fusion_double_cote(tete))
	// 		return (1);
	// 	tete = tete->next_node;
	// }
	return (fusion_str_and_env(tete->next_node));
}
