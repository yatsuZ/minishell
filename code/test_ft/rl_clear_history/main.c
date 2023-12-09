/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:11:47 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/09 18:15:16 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

# define DEFAUT 0
# define VERT 1
# define BLEU 2
# define ROUGE 3

void put_color(int index) {
	if (index == 1)
		printf("\033[1;32m"); // Vert
	else if (index == 2)
		printf("\033[1;34m"); // Bleu
	else if (index == 3)
		printf("\033[1;31m"); // Rouge
	else if (index == 0)
		printf("\033[0m"); // Default
}


void	ajout_dans_history()
{
	printf("fonction add_history * 3\n");
	add_history("Commande 1");
	add_history("Commande 2");
	add_history("Commande 3");
}

void show_history(HIST_ENTRY **history)
{
	if (history) {
		int i = 0;
		while (history[i]) {
			printf("%d: %s\n", i + history_base, history[i]->line);
			i++;
		}
	} else {
		printf("L'historique est vide.\n");
	}
	printf("\n");
}
void	blabla(void)
{
	put_color(VERT);
	printf("\nProgramme test de rl_clear_history.\nCompiler avec Valgrind pour voir la dif!!.\n\n");
	put_color(BLEU);
	printf("Le programme init l'history et ajoutera des element dans history.\n");
	put_color(ROUGE);
	printf("\t- Si il y 0 paramtre -> le programme n'utilisera pas rl_clear_history.(yaura des leak !)\n");
	printf("\t- Si il y + de 1 paramtre -> le programme utilisera rl_clear_history.(yaura pas de leak !)\n");
	put_color(DEFAUT);
	printf("Debut du programme : \n\n");
}

// int main(int argc, char **argv)
// {
// 	(void) argv;
// 	HIST_ENTRY **history;

// 	blabla();
// 	ajout_dans_history();
// 	history = history_list();// Fonction interdite pour minishell je lutilise pour recupere la structure HIST_ENTRY
// 	show_history(history);

// 	put_color(ROUGE);
// 	if (argc == 1)
// 		printf("Je n'utilise pas rl_clear_history !\n");
// 	else
// 	{
// 		put_color(VERT);
// 		printf("J'utilise rl_clear_history !\n");
// 		rl_clear_history();// Libere tout les element de history mais ne libere pas la structure history c'est pour cela que je dois la free plus tard
// 	}
// 	free(history);
// 	history = NULL;
// 	put_color(DEFAUT);
// 	return (0);
// }

int main() {
	char	*input;
	int		i;

	i = 0;
	while (1) {
		put_color(VERT);
		input = readline("Entrez une commande (ou 'exit' pour quitter faire ↑ pour recuperer l'historique): ");
		if (strcmp(input, "exit") == 0) {
			free(input);
			break;
		}
		if (input && *input)
			add_history(input);
		put_color(BLEU);
		printf("Vous avez saisi : %s\n", input);
		free(input);
		put_color(ROUGE);
		if (++i % 5 == 0)
		{
			printf("\nJe suprime l'historique\n");
			clear_history();
		}
		put_color(DEFAUT);
	}
	return 0;
}
