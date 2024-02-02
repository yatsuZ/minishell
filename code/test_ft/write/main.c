/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:13:07 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 11:44:48 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void	ecrire_dans_un_fichier_text(void) {
	int file_descriptor;
	const char *buffer = "Ceci est un message du main.c de write de la fonction \
ecrire_dans_un_fichier_text!\n";
	ssize_t bytes_written;
	// Ouverture du fichier en écriture
	file_descriptor = open("Write_out.txt", O_WRONLY | O_CREAT | O_EXCL, S_IRWXU);

	if (file_descriptor == -1) {
		file_descriptor = open("Write_out.txt", O_WRONLY, S_IRWXU);
		if (file_descriptor == -1)
		{
			perror("Erreur lors de l'ouverture du fichier");
			return ;
		}
	}
	// Écriture dans le fichier
	bytes_written = write(file_descriptor, buffer, strlen(buffer));
	if (bytes_written == -1) {
		 perror("Erreur lors de l'écriture dans le fichier");
		 close(file_descriptor);
		return ;
	}
	// Fermeture du fichier
	close(file_descriptor);
}

void	ecrire_dans_terminal(void)
{
	const char *message = "\033[1;32mBonjour, Le terminal!\n";
	ssize_t bytes_written;

	// Écriture dans la sortie standard (le terminal)
	bytes_written = write(STDOUT_FILENO, message, strlen(message));

	if (bytes_written == -1) {
		perror("Erreur lors de l'écriture dans la sortie standard");
	}
}

int	main(void)
{
	ecrire_dans_un_fichier_text();
	ecrire_dans_terminal();
	// Écriture dans un socket réseau;
	return (212);
}
