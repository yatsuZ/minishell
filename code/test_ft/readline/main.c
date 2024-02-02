/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:31:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/01 20:19:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	put_color(int index)
{
	printf("\033[1;31m");
	if (index == 1)
		printf("\033[1;32m");
	else if (index == 2)
		printf("\033[1;34m");
}

void	test_readline(int i, int na_jammais_parler)
{
	char	*input;
	
	while (i++ < 10) {
		put_color(1);
		input = readline("\n>\t");
		put_color(2);
		if (input[0] == 0)
			printf("\n...\n");
		else
		{
			na_jammais_parler = 0;
			printf("%d>\t%s\n", i, input);
		}

		free(input);
		input = NULL;
	}

	put_color(0);
	if (na_jammais_parler)
		printf("\n\nT'es pas un bavard toi -_- c'est pas drole aller chao.\n");
	else
		printf("\n\nFin du programme.\n");
}

int	main(void)
{
	put_color(2);
	printf("Je suis le programme \"readline_Test_Programme\" et\n");
	put_color(0);
	printf("Je vais répéter ce que tu dis. ET SANS LEAK!!\n\n\n");
	test_readline(0, 1);
	return (0);
}