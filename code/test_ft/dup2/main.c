/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:24:48 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:33:19 by yzaoui           ###   ########.fr       */
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

    int copy_fd = open("cpy_makefile.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (copy_fd == -1) {
        perror("Erreur lors de l'ouverture du fichier de copie");
        return 1;
    }
    printf("Descripteur d'origine : %d\n", fd);
    printf("Descripteur dupliqué : %d\n", copy_fd);

    int result = dup2(fd, copy_fd);
    if (result == -1) {
        perror("Erreur lors de la duplication du descripteur de fichier");
        return 1;
    }

    printf("Descripteur d'origine : %d\n", fd);
    printf("Descripteur dupliqué : %d\nresult = %d\n", copy_fd, result);

    close(fd);
    close(copy_fd);

    return 0;
}
