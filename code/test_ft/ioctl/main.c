/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:00:19 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 22:05:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h> // Pour inclure la déclaration de close

int main() {
    // Utilisation de STDIN_FILENO pour lire à partir de l'entrée standard (le terminal)
    int fd = STDIN_FILENO;

    // Exemple d'utilisation : obtenir la taille du terminal associé au descripteur
    struct winsize size;
    if (ioctl(fd, TIOCGWINSZ, &size) == -1) {
        perror("Erreur lors de l'obtention de la taille du terminal");
        return 1;
    }

    printf("Lignes: %d, Colonnes: %d\n", size.ws_row, size.ws_col);

    return 0;
}
