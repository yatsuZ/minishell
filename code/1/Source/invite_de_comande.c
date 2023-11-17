/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite_de_comande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:13:16 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/17 15:20:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"

int	ft_strcpm(char *s1, char *s2)
{
	long	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

void	invite_de_comande(void)
{
	char	*input;
	int		its_exit;
	char	*entree;

	its_exit = 1;
	printf("\033[31mRouge\033[0m\n");
	printf("\033[32mVert\033[0m\n");
	printf("\033[33mJaune\033[0m\n");
	printf("\033[34mBleu\033[0m\n");
	printf("\033[35mMagenta\033[0m\n");
	printf("\033[36mCyan\033[0m\n");
	printf("\033[37mBlanc\033[0m\n");
	entree = "\n\033[31mMini-Shell\033[0m\033[33mIlham\033[0m\033\
[32mYassine\033[0m\033[34m>\033[0m";
	while (its_exit)
	{
		input = readline(entree);
		printf("Vous avez ecris : %s", input);
		if (!input || ft_strcpm(input, "exit"))
			its_exit = 0;
		free(input);
		input = NULL;
	}
}
