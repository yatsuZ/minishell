/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:00:11 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/07 14:27:44 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int file_descriptor;
	// Ouvrir un fichier en écriture seulement, le créer s'il n'existe pas
	file_descriptor = open("obj", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (file_descriptor == -1)
		perror("Erreur lors de l'ouverture du fichier");
	else {
		printf("Fichier ouvert avec succès. Descripteur de fichier : %d\n", file_descriptor);
		// Autres opérations sur le fichier...
		close(file_descriptor); // Fermeture du fichier
	}
	return (0);
}
