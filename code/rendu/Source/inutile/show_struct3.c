/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:28:05 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/31 16:49:39 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	show_all_rd(t_redirecte *rd, size_t i)
{
	if (!rd)
		return ;
	put_color_txt(MAGENTA);
	printf("-- RD [%ld] c'est un : ", i);
	show_type_input(rd->type_rd);
	printf("\n");
	put_color_txt(VERT);
	if (rd->type_rd == R_IN_LIMIT)
		printf("string limite = ");
	else if (rd->type_rd == R_OUT)
		printf("Fichier de sortie avec supression = ");
	else if (rd->type_rd == R_OUT_ADD)
		printf("Fichier de sortie avec ajoue = ");
	else if (rd->type_rd == R_IN)
		printf("Fichier d'entre = ");
	else
		printf("ERROR = ");
	put_color_txt(BLEU);
	if (rd->type_rd == R_IN_LIMIT && rd->va_activate)
		printf("VA ON \n\"%s\"\n", rd->str_file);
	else if (rd->type_rd == R_IN_LIMIT)
		printf("VA OFF\n\"%s\"\n", rd->str_file);
	else
		printf("%s\n", rd->str_file);
	show_all_rd(rd->next, (i + 1));
}

void	show_execute(t_execute *exe, size_t i)
{
	size_t	j;

	j = 0;
	if (i == 0)
		printf("\n\n");
	put_color_txt(ROUGE);
	printf("----------------- EXECUTE [%ld]\n", i);
	put_color_txt(JAUNE);
	printf("exe adresse : %p\n", exe);
	put_color_txt(EMPTY_COLOR);
	if (!exe)
		return ;
	printf("CMD = \"%s\"\n", exe->cmd);
	put_color_txt(CYAN);
	if (!exe->arg)
		printf("Pas darguement.\n");
	else
		printf("ALL ARG :\n");
	while (exe->arg && exe->arg[j])
	{
		printf("\t- ARG[%ld] : \"%s\"\n", j, exe->arg[j]);
		j++;
	}
	show_all_rd(exe->all_rd, 0);
	show_execute(exe->pip, (i + 1));
}

void	show_tab(char **t)
{
	size_t	i;

	i = 0;
	while (t && t[i])
	{
		printf("t[%ld] = %s\n", i, t[i]);
		i++;
	}
	if (t)
		printf("t[%ld] = %s\n", i, t[i]);
}
