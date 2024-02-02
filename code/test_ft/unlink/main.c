/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:21:39 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 13:27:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    if (unlink("a_suprimer") == 0) {
        printf("Fichier supprimé avec succès.\n");
    } else {
        perror("Erreur lors de la suppression du fichier");
    }
    return 0;
}