/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:24:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 21:26:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *terminal = ttyname(STDIN_FILENO);
    if (terminal != NULL) {
        printf("Le terminal associé à la sortie standard est : %s\n", terminal);
    } else {
        printf("La sortie standard n'est pas associée à un terminal.\n");
    }
    return 0;
}
