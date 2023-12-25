/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:32:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 00:02:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// a remplacer

static void	first_define_tinput(t_node *n, int option);

static void	previous_no_define(t_node *n)
{
	if (n->str[0] == '\"')
		n->type_input = DOUBLE_COTE;
	else if (n->str[0] == '\'')
		n->type_input = SINGLE_COTE;
	else if (n->str[0] == '\t' || n->str[0] == ' ')
		n->type_input = SEPARATOR;
	else if (n->str[0] == '$')
		n->type_input = VA_ENV;
	if (n->type_input == VA_ENV || n->type_input == SEPARATOR)
		return (first_define_tinput(n->next_node, NON_DEFINI));
	first_define_tinput(n->next_node, n->type_input);
}

static void	previous_double_cote(t_node *n)
{
	if (n->str[0] == '\"')
	{
		n->type_input = DOUBLE_COTE;
		return (first_define_tinput(n->next_node, NON_DEFINI));
	}
	n->type_input = STR;
	if (n->str[0] == '$')
		n->type_input = VA_ENV;
	first_define_tinput(n->next_node, DOUBLE_COTE);
}

static void	previous_single_cote(t_node *n)
{
	if (n->str[0] == '\'')
	{
		n->type_input = SINGLE_COTE;
		return (first_define_tinput(n->next_node, NON_DEFINI));
	}
	n->type_input = STR;
	first_define_tinput(n->next_node, SINGLE_COTE);
}

void	first_define_tinput(t_node *n, int option)
{
	if (!n)
		return ;
	else if (option == NON_DEFINI)
		previous_no_define(n);
	else if (option == DOUBLE_COTE)
		previous_double_cote(n);
	else if (option == SINGLE_COTE)
		previous_single_cote(n);
}

// Le premier parsing cherche :
// 1. Les single cote ou double.
// 2. Les variable d'environement.
// 3. Les seperateur entre chaque arguement.
// Puis fusion les string et la VA_ENV et retourne 1 si une cote
// n'est pas fermée Dois fusione tout les str donc modifier
// node + verifier si l'input ferme ces
// cote et fusion la va_d'envirnement si elle est legit.
int	first_parsing(t_all_struct *all)
{
	if (all->prompte->all_cmd_line == NULL)
		return (0);
	first_define_tinput(all->prompte->all_cmd_line, NON_DEFINI);
	return (fusion_str_and_env(all->prompte->all_cmd_line));
}
