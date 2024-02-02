/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:23:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/19 18:48:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	pwd(void)
{
    char path[1024]; // Tampon pour stocker le chemin

    // Obtention du chemin absolu du répertoire de travail
    if (getcwd(path, sizeof(path)) != NULL)
        printf("Le chemin absolu du répertoire de travail est : %s\n", path);
    else
        perror("Erreur lors de la récupération du répertoire de travail");
}

int main() {
	pwd();
    // Changer le répertoire de travail vers "./obj"
    if (chdir("~") != 0)
        perror("Erreur lors du changement de répertoire");

    printf("Le répertoire de travail a été changé.\n");
	pwd();
    return 0;
}
