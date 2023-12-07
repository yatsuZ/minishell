/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:05:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 11:13:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Signal SIGINT reçu.\nsignum = %d\n", signum);
    signal(SIGINT, SIG_DFL);
}

int main() {
    struct sigaction new_action, old_action;

    // Spécifier le gestionnaire de signal pour SIGINT
    new_action.sa_handler = sigint_handler;
    new_action.sa_flags = 0;

    // Associer le nouvel handler à SIGINT et stocker l'ancien
    sigaction(SIGINT, &new_action, &old_action);

    // Continuer l'exécution du programme
    while (1) {
        // Votre code ici
    }

    return 0;
}
