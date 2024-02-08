/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:05:40 by ilouacha          #+#    #+#             */
/*   Updated: 2024/02/08 08:36:10 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Minishell.h"

//faire les siganux ici
int	ft_siganux(void)
{
	pritnf("On doit faire les signaux ici\n");
}

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

void	child_signal(int num)
{
	if (num == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_code = 130;
	}
	if (num == SIGQUIT)
		g_exit_code = 131;
}

void	signal_in_fork(void)
{
	signal(SIGINT, signal_in_child);
	signal(SIGQUIT, signal_in_child);
}

void	father(int status)
{
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
		{
			ft_putstr_fd("\n", 2);
			g_exit_code = 130;
		}
		else if (WTERMSIG(status) == 3)
		{
			ft_putstr_fd(" Quit (core dumped)\n", 2);
			g_exit_code = 131;
		}
		else
			g_exit_code = 128 + WTERMSIG(status);
	}
}


void	handle_cltr_slach(int signal)
{
	signal(num_du_signal,SIG_IGN)
}

// from Imen

int	verif_exit_code(t_cmd *head, t_cmd *cmd_exec, t_data *data)
{
	if (g_exit_code != 130)
	{
		g_exit_code = 1;
		ft_free_pipe(data, cmd_exec);
		ft_lstclear_command(&head);
		return (g_exit_code);
	}
	else
	{
		g_exit_code = 130;
		ft_free_pipe(data, cmd_exec);
		ft_lstclear_command(&head);
		return (g_exit_code);
	}
}

void	init_signal(int sig_int, int sig_quit)
{
	if (sig_int == IGN)
		signal(SIGINT, SIG_IGN);
	if (sig_int == HER)
		signal(SIGINT, SIG_IGN);
	if (sig_int == SHE)
		signal(SIGINT, sig_handler);
	if (sig_quit == IGN)
		signal(SIGQUIT, SIG_IGN);
	if (sig_quit == HER)
		signal(SIGQUIT, SIG_IGN);
	if (sig_quit == SHE)
		signal(SIGQUIT, sig_handler);
}

void	signal_in_father(int status)
{
	if (WIFEXITED(status))
		g_exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
		{
			ft_putstr_fd("\n", 2);
			g_exit_code = 130;
		}
		else if (WTERMSIG(status) == 3)
		{
			ft_putstr_fd(" Quit (core dumped)\n", 2);
			g_exit_code = 131;
		}
		else
			g_exit_code = 128 + WTERMSIG(status);
	}
}
