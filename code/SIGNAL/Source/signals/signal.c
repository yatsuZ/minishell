/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:18:14 by ilouacha          #+#    #+#             */
/*   Updated: 2024/01/23 19:14:47 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

signal(SIGINT, &handle_ctrl_c);
extern int	g_exit_stt;

// En C: kill (num_du_processus_destinataire, num_du_signal)
// En Shell: kill -num_du_signal num_du_processus


void	handle_ctrl_c(int signal)
{
	g_exit_stt += signal;
	if (signal == SIGINT)
	{
		g_exit_stt = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_ctrl_D(int signal)
{
	g_exit_stt += signal;
	if (signal == EOF)

	char buffer[100];
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		// Traitement du texte lu
		printf("Vous avez entré : %s", buffer);
	}
}

void	handle_cltr_slach(int signal)
{
	signal(num_du_signal,SIG_IGN)
}

