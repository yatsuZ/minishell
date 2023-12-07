/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:51:11 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 14:03:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"example", "arg1", "arg2", NULL};
    char *env[] = {NULL};
	int	res;

    printf("Je suis dans le main principal de execve\n\n");
	res = execve("./EXECVE2_Test_Programme", args, env);
    printf("\nQue passa ?\n\n");
    if (res == -1) {
        perror("Erreur lors de l'exécution du programme");
    }
    printf("Ce message ne sera pas atteint après execve.\nres = %d\n", res);
    return 0;
}
