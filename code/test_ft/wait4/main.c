/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:05:58 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/06 01:20:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;
    struct rusage usage;

    child_pid = fork();

    if (child_pid == -1) {
        perror("Erreur lors de la création du processus enfant");
        return 1;
    } else if (child_pid == 0) {
        // Travail du processus enfant...
        printf("Je suis le processus enfant (PID : %d).\n", getpid());
        return 42;
    } else {
        printf("Je suis le processus parent (PID : %d).\n", getpid());
        
        wait4(child_pid, &status, 0, &usage);

        if (WIFEXITED(status)) {
            printf("Le processus enfant s'est terminé avec le code de sortie : %d.\n", WEXITSTATUS(status));
        }

        // Informations sur l'utilisation des ressources par le processus enfant
        printf("Utilisation des ressources par le processus enfant : \n");
        printf("Temps CPU utilisé : %ld.%06ld secondes\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("Temps CPU système utilisé : %ld.%06ld secondes\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    }

    return 0;
}
