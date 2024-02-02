/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:29:21 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 22:55:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void printTermiosAttributes(struct termios term) {
    printf("c_iflag: %lx\n", (unsigned long)term.c_iflag);
    printf("c_oflag: %lx\n", (unsigned long)term.c_oflag);
    printf("c_cflag: %lx\n", (unsigned long)term.c_cflag);
    printf("c_lflag: %lx\n", (unsigned long)term.c_lflag);
    printf("c_line: %x\n", term.c_line);
    for (int i = 0; i < NCCS; ++i) {
        printf("c_cc[%d]: %x\n", i, term.c_cc[i]);
    }
    printf("c_ispeed: %x\n", term.c_ispeed);
    printf("c_ospeed: %x\n", term.c_ospeed);
}


int main() {
    int fd = STDOUT_FILENO;  // Descripteur de fichier associé à la sortie standard
    struct termios term;
    
    if (tcgetattr(fd, &term) != 0) {
        perror("Erreur lors de la récupération des attributs du terminal");
        return 1;
    }

	printTermiosAttributes(term);
    // Utilisation de la structure term pour accéder aux attributs du terminal

    return 0;
}
