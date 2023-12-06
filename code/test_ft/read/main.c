/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:14:00 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/06 00:16:27 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
	int file_descriptor;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];

	// Ouvrir un fichier en lecture seule
	file_descriptor = open("makefile", O_RDONLY);

	if (file_descriptor == -1) {
		perror("Erreur lors de l'ouverture du fichier");
		return 1;
	}

	// Lecture depuis le fichier
	bytes_read = read(file_descriptor, buffer, BUFFER_SIZE);

	if (bytes_read == -1) {
		perror("Erreur lors de la lecture du fichier");
		close(file_descriptor);
		return 1;
	} else if (bytes_read == 0) {
		printf("Fin de fichier atteinte.\n");
	} else {
		printf("%zd octets lus :\n%s\n", bytes_read, buffer);
	}

	// Fermeture du fichier
	close(file_descriptor);

	return (0);
}
