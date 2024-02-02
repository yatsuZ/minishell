/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:53:52 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:57:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    DIR *directory;
    struct dirent *dir_entry;

    // Ouvrir le répertoire
    directory = opendir("./obj");

    if (directory) {
        // Lecture des entrées du répertoire
        while ((dir_entry = readdir(directory)) != NULL) {
            printf("Nom du fichier : %s\n", dir_entry->d_name);
        }

        // Fermeture du répertoire
        closedir(directory);
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
        exit(EXIT_FAILURE);
    }

    return 0;
}
