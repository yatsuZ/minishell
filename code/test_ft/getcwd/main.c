/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:05:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 12:21:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    char path[1024]; // Tampon pour stocker le chemin

    // Obtention du chemin absolu du répertoire de travail
    if (getcwd(path, sizeof(path)) != NULL) {
        printf("Le chemin absolu du répertoire de travail est : %s\n", path);
    } else {
        perror("Erreur lors de la récupération du répertoire de travail");
        return 1;
    }

    return 0;
}
