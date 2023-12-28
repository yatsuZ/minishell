/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:05:24 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/28 15:24:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char    *r;
    // char path[1024]; // Tampon pour stocker le chemin

    // Obtention du chemin absolu du répertoire de travail
    r = getcwd(NULL, 0);
    printf("retour de la ft : %s\n", r);
    free(r);
    r = NULL;
    // if (getcwd(path, sizeof(path)) != NULL) {
    //     printf("Le chemin absolu du répertoire de travail est : %s\n", path);
    // } else {
    //     perror("Erreur lors de la récupération du répertoire de travail");
    //     return 1;
    // }

    return 0;
}
