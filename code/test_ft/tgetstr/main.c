/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:18:40 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/08 00:21:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <term.h>

int main() {
    char *clear_screene = tgetstr("clear", NULL);
    if (clear_screene != NULL) {
        printf("La séquence pour effacer l'écran : %s\n", clear_screen);
    } else {
        printf("Capacité 'clear' non trouvée dans la base de données terminfo.\n");
    }

    return 0;
}
