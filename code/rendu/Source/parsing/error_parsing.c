/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:30:18 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/15 23:18:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	error_parsing(int iderr)
{
	put_color_txt(ROUGE);
	printf("Error Parsing :\t");
	put_color_txt(JAUNE);
	if (iderr == 0)
		printf("Y a pas d'erreur.");
	else if (iderr == 1)
		printf("SINGLE COTE non refermée.");
	else if (iderr == 2)
		printf("DOUBLE COTE non refermée.");
	else if (iderr == 3)
		printf("PIP a la suite.");
	else if (iderr == 4)
		printf("TERMINE par un PIP.");
	else if (iderr == 5)
		printf("COMMENCE par un PIP.");
	else if (iderr == 6)
		printf("Termine par une REDIRECTION VIDE.");
	else if (iderr == 7)
		printf("REDIRECTION VIDE.");
	else if (iderr == 8)
		printf("New line non interpreter.");
	printf("\n");
	put_color_txt(EMPTY_COLOR);
}
