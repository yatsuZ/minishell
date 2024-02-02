/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:17:30 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 11:33:18 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

int main() {
    sigset_t my_set;

    // Initialiser un ensemble de signaux vide
    if (sigemptyset(&my_set) == -1) {
        perror("Erreur lors de l'initialisation de l'ensemble de signaux");
        return 1;
    }
    else
        printf("L'ensemble des signaux de my_set son à present vide\n.");
    // L'ensemble my_set est maintenant vide, aucun signal n'est inclus

    return 0;
}
