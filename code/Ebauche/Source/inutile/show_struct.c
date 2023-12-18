/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:38:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/18 01:14:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	show_prompt(t_prompt *promp)
{
	t_node	*tmp;
	int		i;

	put_color_txt(JAUNE);
	printf("adresse de la strcuture promp : %p\n", promp);
	printf("Invitée de commande :");
	put_color_txt(EMPTY_COLOR);
	printf("%s\n", promp->invite);
	tmp = promp->all_cmd_line;
	i = 0;
	while (tmp)
	{
		put_color_txt(BLEU);
		printf("Mot numéro ");
		put_color_txt(ROUGE);
		printf("[%d]: \t", i++);
		put_color_txt(VERT);
		printf("\"%s\"\n", tmp->str);
		tmp = tmp->next_node;
	}
	put_color_txt(EMPTY_COLOR);
}