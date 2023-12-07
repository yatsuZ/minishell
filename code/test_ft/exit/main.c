/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:51:22 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 11:59:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	fonction_en_de_hors_du_main(void)
{
	printf("Je ne suis pas dans le main.");
	exit(0);
}
int main() {
    printf("Le programme commence :).\n");
	fonction_en_de_hors_du_main();
    printf("De retour dans le main.\n");
    return (1);
}
