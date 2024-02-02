/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:08:22 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/08 00:13:09 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <term.h>

int main() {
    int cols = tgetnum("cols");
    int linese = tgetnum("linese");

    if (cols > 0 && linese > 0) {
        printf("Le terminal a une taille de %d colonnes et %d lignes.\n", cols, linese);
    } else {
        printf("Impossible d'obtenir les informations sur la taille du terminal.\n");
    }

    return 0;
}
