/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:32:58 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 12:47:23 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void print_stat_info(const struct stat *file_info) {
    printf("Taille du fichier : %lld octets\n", (long long)file_info->st_size);
    printf("Permissions : %o\n", file_info->st_mode & 0777);

    // Affichage de la date de dernière modification
    printf("Dernière modification : %s", ctime(&file_info->st_mtime));

    // Affichage de l'utilisateur et du groupe propriétaires
    struct passwd *user_info = getpwuid(file_info->st_uid);
    struct group *group_info = getgrgid(file_info->st_gid);
    printf("Propriétaire : %s\n", (user_info != NULL) ? user_info->pw_name : "Inconnu");
    printf("Groupe : %s\n", (group_info != NULL) ? group_info->gr_name : "Inconnu");

    printf("ID du périphérique : %ld\n", (long)file_info->st_dev);
    printf("Numéro d'inode : %ld\n", (long)file_info->st_ino);
    printf("Nombre de liens : %ld\n", (long)file_info->st_nlink);
    printf("ID utilisateur : %ld\n", (long)file_info->st_uid);
    printf("ID groupe : %ld\n", (long)file_info->st_gid);
    printf("ID périphérique spécial : %ld\n", (long)file_info->st_rdev);
    printf("Taille du bloc : %ld\n", (long)file_info->st_blksize);
    printf("Nombre de blocs alloués : %ld\n", (long)file_info->st_blocks);
}

int main() {
    const char *file_path = "./makefile"; // Chemin de votre fichier
    struct stat file_info;

    // Obtenir des informations sur le fichier
    if (stat(file_path, &file_info) != 0) {
        perror("Erreur lors de l'obtention des informations sur le fichier");
        return 1;
    }
	print_stat_info(&file_info);

    return 0;
}
