/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:12:10 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/04 00:25:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
	char *input;
	// Initialisation de l'historique
	using_history();
	// Boucle pour lire plusieurs commandes
	while (1) {
		// Lecture de l'entrée utilisateur
		input = readline("Entrez une commande (ou 'exit' pour quitter): ");
		// Vérification si l'utilisateur veut quitter
		if (strcmp(input, "exit") == 0) {
			free(input);
			break;
		}
		// Ajout de l'entrée à l'historique si elle n'est pas vide
		if (input && *input) {
			add_history(input);
		}
		// Affichage de l'entrée saisie
		printf("Vous avez saisi : %s\n", input);
		// Libération de la mémoire allouée par readline
		free(input);
	}
	return 0;
}
