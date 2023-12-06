/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:37:15 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/06 00:42:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t child_pid;

	child_pid = fork();
	printf("Je suis apres le fork :)\n");
	if (child_pid == -1) {
		perror("Erreur lors de la création du processus enfant");
		return 1;
	} else if (child_pid == 0) {
		printf("Je suis le processus enfant (PID : %d).\n", getpid());
	} else {
		printf("Je suis le processus parent (PID : %d) du processus enfant (PID : %d).\n", getpid(), child_pid);
	}

	return 0;
}
