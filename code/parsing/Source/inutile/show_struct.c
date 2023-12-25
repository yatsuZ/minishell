/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:38:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/25 22:35:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	show_type_input2(t_node *n)
{
	if (n->type_input == CMD)
		printf("CMD");
	else if (n->type_input == ARGUMENT)
		printf("ARGUMENT");
	else if (n->type_input == VA_ENV)
	{
		put_color_txt(JAUNE);
		printf("VA_ENV");
	}
	else if (n->type_input == VA_RETOUR)
		printf("VA_RETOUR");
	else if (n->type_input == R_IN)
		printf("R_IN");
	else if (n->type_input == R_OUT)
		printf("R_OUT");
	else if (n->type_input == R_IN_LIMIT)
		printf("R_IN_LIMIT");
	else if (n->type_input == R_OUT_ADD)
		printf("R_OUT_ADD");
	else if (n->type_input == F_RD)
		printf("F_RD");
	else if (n->type_input == PIP)
		printf("PIP");
	put_color_txt(EMPTY_COLOR);
}

void	show_type_input(t_node *n)
{
	put_color_txt(VERT);
	if (n->type_input == NON_DEFINI)
	{
		put_color_txt(ROUGE);
		printf("NON defini!!");
	}
	else if (n->type_input == STR)
	{
		put_color_txt(EMPTY_COLOR);
		printf("STR");
	}
	else if (n->type_input == SINGLE_COTE)
	{
		put_color_txt(BLEU);
		printf("SINGLE_COTE");
	}
	else if (n->type_input == DOUBLE_COTE)
	{
		put_color_txt(CYAN);
		printf("DOUBLE_COTE");
	}
	else if (n->type_input == SEPARATOR)
		printf("SEPARATOR");
	show_type_input2(n);
}

void	show_prompt(t_prompt *promp)
{
	t_node	*tmp;

	put_color_txt(JAUNE);
	printf("adresse de la strcuture promp : %p\n", promp);
	printf("Invitée de commande :");
	put_color_txt(EMPTY_COLOR);
	printf("%s\n", promp->invite);
	tmp = promp->all_cmd_line;
	while (tmp)
	{
		printf("---\n");
		put_color_txt(BLEU);
		printf("Node numéro");
		put_color_txt(ROUGE);
		printf("[%ld]: \t", tmp->index);
		put_color_txt(VERT);
		printf("\"%s\"\n", tmp->str);
		printf("Type node = ");
		show_type_input(tmp);
		printf("\n");
		tmp = tmp->next_node;
	}
	put_color_txt(EMPTY_COLOR);
}
