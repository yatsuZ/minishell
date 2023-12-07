/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:13:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 22:21:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    struct termios term;
    int fd = STDOUT_FILENO;  // Utilisation du descripteur de fichier du terminal de sortie

    // Obtention des paramètres actuels du terminal
    if (tcgetattr(fd, &term) == -1) {
        perror("Erreur lors de la récupération des paramètres du terminal");
        exit(EXIT_FAILURE);
    }

    // Modification des paramètres du terminal (par exemple, désactiver le mode canonique)
    term.c_lflag &= ICANON;  // Désactiver le mode canonique

    // Application des changements
    if (tcsetattr(fd, TCSANOW, &term) == -1) {
        perror("Erreur lors de la configuration des paramètres du terminal");
        exit(EXIT_FAILURE);
    }

    // Le terminal est maintenant configuré avec les nouveaux attributs.

    return 0;
}
