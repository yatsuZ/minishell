/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:51:10 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/06 00:57:37 by yzaoui           ###   ########.fr       */
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
		sleep(1);
		return 42;
	} else {
		printf("Je suis le processus parent (PID : %d) du processus enfant (PID : %d).\n", getpid(), child_pid);
		// Attente non bloquante du processus enfant
		sleep(1);
		wait_pid = waitpid(child_pid, &status, WNOHANG);
		if (wait_pid == 0) {
			printf("Le processus enfant (PID : %d) n'est pas encore terminé.\n", child_pid);
		} else if (wait_pid == -1) {
			perror("Erreur lors de l'attente du processus enfant");
			return 1;
		} else {
			if (WIFEXITED(status)) {
				printf("Le processus enfant (PID : %d) s'est terminé avec le code de sortie : %d.\n", wait_pid, WEXITSTATUS(status));
			}
		}
	}
	return 0;
}
