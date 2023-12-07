/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:01:23 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 23:39:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int main() {
    char term_buffer[1024];
    const char *term_name = "xterm-256color"; // Nom du terminal
    if (tgetent(term_buffer, term_name) != 1) {
        perror("Erreur lors du chargement des informations du terminal");
        return 1;
    }

    // Exemple : afficher la taille du terminal
    int rows = tgetnum("lines");
    int cols = tgetnum("cols");
    printf("Taille du terminal : %dx%d\n", cols, rows);

    // Exemple : afficher une capacité spécifique
    char *clear_screen = tgetstr("clear", NULL);
    if (clear_screen != NULL) {
        printf("Capacité de nettoyage du terminal : %s\n", clear_screen);
    } else {
        printf("Aucune capacité de nettoyage trouvée pour le terminal %s.\n", term_name);
    }

    // Exemple : obtenir et afficher une chaîne d'échappement spécifique
    char *cursor_invisible = tgetstr("civis", NULL);
    if (cursor_invisible != NULL) {
        printf("Chaîne pour masquer le curseur : %s\n", cursor_invisible);
    } else {
        printf("Aucune chaîne pour masquer le curseur trouvée pour le terminal %s.\n", term_name);
    }

    return 0;
}
