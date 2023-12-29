/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:12:59 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/29 18:15:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static void	show_type_input3(t_type_input ti)
{
	if (ti == PIP)
	{
		put_color_txt(MAGENTA);
		printf("PIP");
	}
	put_color_txt(EMPTY_COLOR);
}

static void	show_type_input2(t_type_input ti)
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
