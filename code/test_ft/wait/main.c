/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:45:35 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/06 00:48:06 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t child_pid, wait_pid;
	int status;
	child_pid = fork();
	if (child_pid == -1) {
		perror("Erreur lors de la création du processus enfant");
		return 1;
	} else if (child_pid == 0) {
		printf("Je suis le processus enfant (PID : %d).\n", getpid());
		// Travail du processus enfant...
		return 42;
	} else {
		printf("Je suis le processus parent (PID : %d) du processus enfant (PID : %d).\n", getpid(), child_pid);
		wait_pid = wait(&status);
		if (wait_pid == -1) {
			perror("Erreur lors de l'attente du processus enfant");
			return 1;
		}
		if (WIFEXITED(status)) {
			printf("Le processus enfant (PID : %d) s'est terminé avec le code de sortie : %d.\n", wait_pid, WEXITSTATUS(status));
		}
	}
	return 0;
}
