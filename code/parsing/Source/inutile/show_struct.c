/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:38:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 20:57:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	show_type_input3(t_type_input ti)
{
	if (ti == PIP)
	{
		put_color_txt(MAGENTA);
		printf("PIP");
	}
	put_color_txt(EMPTY_COLOR);
}

void	show_type_input2(t_type_input ti)
{
	if (ti == CMD)
		printf("CMD");
	else if (ti == ARGUMENT)
		printf("ARGUMENT");
	else if (ti == VA_ENV)
	{
		put_color_txt(JAUNE);
		printf("VA_ENV");
	}
	else if (ti == VA_RETOUR)
		printf("VA_RETOUR");
	put_color_txt(BLANC);
	if (ti == R_IN)
		printf("R_IN");
	else if (ti == R_OUT)
		printf("R_OUT");
	else if (ti == R_IN_LIMIT)
		printf("R_IN_LIMIT");
	else if (ti == R_OUT_ADD)
		printf("R_OUT_ADD");
	else if (ti == F_RD)
		printf("F_RD");
	show_type_input3(ti);
}

void	show_type_input(t_type_input ti)
{
	put_color_txt(VERT);
	if (ti == NON_DEFINI)
	{
		put_color_txt(ROUGE);
		printf("NON defini!!");
	}
	else if (ti == STR)
	{
		put_color_txt(EMPTY_COLOR);
		printf("STR");
	}
	else if (ti == SINGLE_COTE)
	{
		put_color_txt(BLEU);
		printf("SINGLE_COTE");
	}
	else if (ti == DOUBLE_COTE)
	{
		put_color_txt(CYAN);
		printf("DOUBLE_COTE");
	}
	else if (ti == SEPARATOR)
		printf("SEPARATOR");
	show_type_input2(ti);
}

void	show_node(t_node *tmp)
{
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
		show_type_input(tmp->type_input);
		printf("\n");
		tmp = tmp->next_node;
	}
	put_color_txt(EMPTY_COLOR);
	printf("---\n");
}

void	show_prompt(t_prompt *promp)
{
	put_color_txt(JAUNE);
	printf("adresse de la strcuture promp : %p\n", promp);
	printf("Invitée de commande :");
	put_color_txt(EMPTY_COLOR);
	printf("%s\n", promp->invite);
	printf("input BRUT = %s\n", promp->brut);
	show_node(promp->all_cmd_line);
	put_color_txt(MAGENTA);
	printf("Nombre de PIP\t: %d\n", promp->nbr_of_pip);
	put_color_txt(CYAN);
	printf("Nombre de RD \t: %d\n", promp->nbr_of_rd);
	put_color_txt(EMPTY_COLOR);
}

void	show_all_va(t_env *env)
{
	size_t	i;

	i = 0;
	put_color_txt(JAUNE);
	printf("adresse de la strcuture env : %p\n", env);
	if (!env)
	{
		put_color_txt(ROUGE);
		printf("ENV est null\n");
	}
	else
	{
		while (env)
		{
			printf("-----\t%ld\n", i++);
			put_color_txt(VERT);
			printf("KEY\t\t=\t\"%s\"\n", env->key);
			put_color_txt(BLEU);
			printf("VALUE\t=\t\"%s\"\n", env->value);
			env = env->next_va;
		}
			put_color_txt(ROUGE);
			printf("-----\t%ld\nKEY\t\t=\t\"%p\"\nVALUE\t=\t\"%p\"\n-----\n", i, env, env);
	}
	put_color_txt(EMPTY_COLOR);
}
