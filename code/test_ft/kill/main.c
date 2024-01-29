/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:37:15 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 19:37:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	pid_t pid = getpid(); // Récupérer l'ID du processus en cours
	int result;

	// Envoyer un signal SIGTERM à mon propre processus
	result = kill(pid, 0);

	printf("resulat de kill = %d\n", result);
	if (result == -1) {
		perror("Erreur lors de l'envoi du signal");
		return 1;
	}

	return 0;
}
