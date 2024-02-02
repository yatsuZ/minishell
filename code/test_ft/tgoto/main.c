/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:22:40 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/08 00:37:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <term.h>

int main() {
    // Initialisation de la fenêtre Curses
    initscr();

    // Obtention de la taille du terminal
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Déplacement du curseur à une position spécifique
    int x = cols / 2;  // Demi-largeur du terminal
    int y = rows / 2;  // Demi-hauteur du terminal

    char *cursor_position = tgoto(cursor_address, x, y);

    // Affichage du résultat
    printf("Cursor position: %s\n", cursor_position);

    // Fermeture de la fenêtre Curses
    endwin();

    return 0;
}
