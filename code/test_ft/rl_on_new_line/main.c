/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:48:33 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/19 17:34:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Indique à readline une nouvelle ligne pour la prochaine entrée
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>

extern int    g_exit_stt;

void    handle_ctrl_c(int signal)//decomente pour voir le truc en action et recomenter les pour voir la diff
{
    // g_exit_stt += signal;
    if (signal == SIGINT)
    {
        // g_exit_stt = 130;
        printf("\n");
        rl_on_new_line();
        // rl_replace_line("", 0);
        // rl_redisplay();
    }
}


int main() {
	int	i;
    char *input;

	i = 0;
    signal(SIGINT, &handle_ctrl_c);
    // Demande à l'utilisateur de saisir une ligne
	while (i++ < 10)
	{
		input =readline("Entrez une ligne : ");
        printf("input = %s\n", input);
        free(input);
	}
    return 0;
}
