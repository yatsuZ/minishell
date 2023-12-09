/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:48:33 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/09 18:29:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Indique à readline une nouvelle ligne pour la prochaine entrée
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
	int	i;
    char *input;

	i = 0;
    // Initialisation de Readline
    rl_initialize();

    // Demande à l'utilisateur de saisir une ligne
	while (i++ < 10)
	{
		input =readline("Entrez une ligne : ");
	    // Utilisation de rl_on_new_line()
	    // rl_on_new_line();
	    // Ajout de l'entrée à l'historique de Readline
	    add_history(input);
	    free(input);
	}

    // Affichage de l'historique des commandes
    HIST_ENTRY **history_liste = history_list();
    printf("Historique des commandes :\n");
    if (history_liste != NULL) {
        for (int i = 0; history_liste[i] != NULL; ++i) {
            printf("%d: %s\n", i + 1, history_liste[i]->line);
        }
    }

    // Libération de la mémoire allouée pour l'entrée

    return 0;
}
