/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:23:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 19:16:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	change_va_undescore(t_execute *exe, t_env **env)
{
	char	*new_end;
	size_t	i;

	if (!exe || ft_strcpm(exe->cmd, "exit"))
		return ;
	new_end = NULL;
	i = exe->argc;
	while (exe->arg && i && !new_end)
	{
		new_end = exe->arg[i];
		i--;
	}
	if (new_end == NULL)
		new_end = exe->cmd;
	change_or_add_va(env, "_", new_end, 0);
}

// 1 Faire une ft qui execute la commande ouverture puis fermeture des fichier
int	ft_exec(t_execute *exe, t_all_struct **all)
{
	pid_t	f;
	int		status;

	status = 0;
	// Open rd
	// EXEC
	// RD
	change_va_undescore(exe, &((*all)->all_va));
	if (find_builtin(exe->cmd) != NON_BUILTIN)
		status = exec_builtin(exe, all, find_builtin(exe->cmd));
	else if (exe->cmd)
	{
		if (find_cmd(NULL, &(exe->cmd), all))
		{
			if (access(exe->cmd, F_OK) == 0)
			{
				f = fork();
				if (f == -1)
					printf("ERROR de fork!!\n\n");
				if (!f)
				{
					execve(exe->cmd, exe->arg, (*all)->env);
				}
				waitpid(f, &status, 0);
			}
			else
			{
				print_fd("On ne peut pas executer: \"", 2);
				print_fd(exe->cmd, 2);
				print_fd("\" car soit un dossier ou non les droits\n", 2);
			}
		}
		else
			status = 127;
	}
	return (status);
}

// Fiare une ft qui s'occupe des redirection

//partie importante je vais juste moccupe des builtin
int	ft_all_exec(t_execute *exe, t_all_struct **all)
{
	if (!all)
		end(NULL);
	else if (!(*all))
		end(*all);
	else if (!exe)
		return ((*all)->status);
	// if (exe->pip)
	// 	return (ft_execpip(exe, all));
	return (ft_exec(exe, all));
}
