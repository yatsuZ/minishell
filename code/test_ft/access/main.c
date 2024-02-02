/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:35:53 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/19 18:31:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
	const char *filename = "../access/c1/c2/c3";
	const char *filename2 = "main.c";
	// Vérification de l'existence et des permissions de lecture
	if (access(filename, F_OK) == 0)
		printf("Le fichier : \'%s\' existe et est lisible.\n", filename);
	else
		printf("Le fichier : \'%s\' n'existe pas ou n'est pas lisible.\n", filename);
	if (access(filename2, R_OK) == 0)
		printf("Le fichier : \'%s\' existe et est lisible.\n", filename2);
	else
		printf("Le fichier : \'%s\' n'existe pas ou n'est pas lisible.\n", filename2);
	return (0);
}
