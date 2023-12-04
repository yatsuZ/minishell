/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:55:55 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/02 18:18:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
	// Attente d'une entrée utilisateur
	char *input = readline("> ");
	// Remplacement de la ligne affichée avec rl_replace_line
	rl_replace_line("Nouvelle ligne", 0);
	// Rafraîchissement de l'affichage pour refléter le changement.
	rl_forced_update_display();// Foonction interdit dans minishell.
	// Libération de la mémoire utilisée par l'entrée utilisateur
	free(input);
	return (0);
}
