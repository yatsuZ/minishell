/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_context.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:42:14 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/10 23:46:05 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/Minishell.h"

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
