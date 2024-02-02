/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:19:12 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:22:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("makefile", O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    int copy_fd = dup(fd);
    if (copy_fd == -1) {
        perror("Erreur lors de la duplication du descripteur de fichier");
        return 1;
    }

    printf("Descripteur d'origine : %d\n", fd);
    printf("Descripteur copié : %d\n", copy_fd);

    close(fd);
    close(copy_fd);

    return 0;
}
