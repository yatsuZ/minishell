/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:33:38 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/03 23:31:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include<unistd.h>

int main() {
	rl_initialize(); // Initialisation de Readline
	// Modification du prompt
	char *rl_prompt = "Entrez quelque chose> ";
	// Lecture de la saisie
	char *str = readline(rl_prompt);
	if (str != NULL) {
		printf("Vous avez saisi : %s\n", str);
		// Modification du contenu de la ligne de saisie
		rl_save_prompt(); // Sauvegarde du prompt
		rl_replace_line("Nouvelle saisie", 0); // Remplace la saisie précédente
		rl_redisplay(); // Réaffiche la ligne modifiée
		rl_restore_prompt(); // Restaure le prompt
		// Attends un peu avant de quitter (juste pour observer le changement)
		sleep(2);
		// Libère la mémoire de la saisie
		free(str);
	}
	return 0;
}
