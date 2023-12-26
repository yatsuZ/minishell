/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:30:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:37:16 by yzaoui           ###   ########.fr       */
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
		printf("Les cotes ne sont pas refermée.");
	printf("\n");
	put_color_txt(EMPTY_COLOR);
}
