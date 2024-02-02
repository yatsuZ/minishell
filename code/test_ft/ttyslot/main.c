/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:53:25 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 21:56:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main() {
    int slot = ttyslot();
    if (slot != -1) {
        printf("L'index du terminal associé au processus est : %d\n", slot);
    } else {
        printf("Impossible de trouver l'index du terminal.\n");
    }
    return 0;
}
