/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:29:26 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 11:37:03 by yzaoui           ###   ########.fr       */
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
        printf("L'ensemble des signaux de my_set son à present vide.\n");
    // Ajouter SIGINT à l'ensemble de signaux
    if (sigaddset(&my_set, SIGINT) == -1) {
        perror("Erreur lors de l'ajout de SIGINT à l'ensemble de signaux");
        return 1;
    }
    else
        printf("my_set contient comme signaux : SIGINT.\n");
    // L'ensemble my_set contient maintenant SIGINT

    return 0;
}
