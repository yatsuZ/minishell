/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:50:24 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 19:35:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	g_global = 1;

void sigint_handler2(int signum) {
	printf("Signal SIGINT reçu.\nsignum = %d\n", signum);
	// Rétablir le comportement par défaut pour SIGINT
	g_global = 0;
	while (1)
		printf("????\n\n");
	signal(SIGINT, SIG_DFL);
	
}

int main() {
	__sighandler_t res;

	// Associer le gestionnaire de signal à SIGINT
	res = signal(SIGINT, sigint_handler2);

	printf("Attente de signaux...\n");

	while (g_global) {
		if (res == SIG_DFL)
			printf("Comportement par defaut\n");
		else
			printf("Comportement jsp ?\n");
		printf("Jattend un signal :|\n");
		sleep(1);
	}
	printf("Pas de fork\n");
	return 0;
}
