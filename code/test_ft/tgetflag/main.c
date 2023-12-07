/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:47:23 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/07 23:54:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <curses.h>
#include <term.h>

int main() {
    if (!tgetflag("am")) {
        printf("La fonctionnalité 'auto margin' n'est pas activée sur ce terminal.\n");
    } else {
        printf("La fonctionnalité 'auto margin' est activée sur ce terminal.\n");
    }

    return 0;
}
