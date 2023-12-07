/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:35:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:45:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int filedes[2];
    pid_t pid;
    char buffer[19] = "123456789 12345678\0";

    // Création du tube
    if (pipe(filedes) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Création d'un processus enfant
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processus enfant - lecture depuis le tube
        close(filedes[1]); // Fermeture de l'extrémité d'écriture
        read(filedes[0], buffer, sizeof(buffer));
        printf("Le fils a lu : %s\n", buffer);

        close(filedes[0]); // Fermeture de l'extrémité de lecture
    } else {
        // Processus parent - écriture dans le tube
        close(filedes[0]); // Fermeture de l'extrémité de lecture

        printf("Le parent écrit dans le tube.\n");
        write(filedes[1], "Hello from parent!", 18);

        close(filedes[1]); // Fermeture de l'extrémité d'écriture
    }

    return 0;
}
