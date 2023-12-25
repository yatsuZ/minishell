/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:07:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/19 20:39:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

void	show_color(void)
{
	printf("\033[31mRouge\033[0m\n");
	printf("\033[32mVert\033[0m\n");
	printf("\033[33mJaune\033[0m\n");
	printf("\033[34mBleu\033[0m\n");
	printf("\033[35mMagenta\033[0m\n");
	printf("\033[36mCyan\033[0m\n");
	printf("\033[37mBlanc\033[0m\n");
}

void	put_color_txt(int color)
{
	if (color == ROUGE)
		printf("\033[31m");
	else if (color == VERT)
		printf("\033[32m");
	else if (color == JAUNE)
		printf("\033[33m");
	else if (color == BLEU)
		printf("\033[34m");
	else if (color == MAGENTA)
		printf("\033[35m");
	else if (color == CYAN)
		printf("\033[36m");
	else if (color == BLANC)
		printf("\033[37m");
	else
		printf("\033[0m");
}
