/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:05:40 by ilouacha          #+#    #+#             */
/*   Updated: 2024/02/09 19:29:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

void	signal_in_child(int num)
{
	if (num == SIGINT)
	{
		print_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_signal = 130;
	}
	if (num == SIGQUIT)
		g_exit_signal = 131;
}

void	signal_in_fork(void)
{
	signal(SIGINT, signal_in_child);
	signal(SIGQUIT, signal_in_child);
}

int	signal_in_father(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
		{
			print_fd("\n", 2);
			return (130);
		}
		else if (WTERMSIG(status) == 3)
		{
			print_fd(" Quit (core dumped)\n", 2);
			return (131);
		}
		else
			return (128 + WTERMSIG(status));
	}
	return (status);
}

void	sig_handler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_signal = 130;
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
