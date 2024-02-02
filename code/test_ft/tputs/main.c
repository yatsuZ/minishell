/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:46:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/08 00:49:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <term.h>

int main() {
    // Initialisation de la fenêtre Curses
    initscr();

    // Affichage d'une capacité de contrôle de terminal
    char *clear_screene = tgetstr("clear", NULL);
    if (clear_screene != NULL) {
        tputs(clear_screene, 1, putchar);
        refresh();
    }

    // Fermeture de la fenêtre Curses
    endwin();

    return 0;
}
