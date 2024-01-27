/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/27 15:53:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static int	is_a_option(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i++] != '-')
		return (0);
	while (str[i])
	{
		if (str[i++] != 'n')
			return (0);
	}
	return (str[i] == '\0');
}

static void	ft_echo(char **av, size_t ac, size_t i, t_boolean put_space)
{
	while (i < ac)
	{
		if (av[i])
		{
			if (put_space)
				printf(" ");
			printf("%s", av[i]);
			put_space = TRUE;
		}
		else
			put_space = FALSE;
		i++;
	}
}

int	exec_echo(t_execute *exe, t_all_struct **all)
{
	size_t	i;
	int		option;

	(void) all;
	i = 0;
	if (exe->argc == 0)
		return (printf("\n"), 0);
	if (is_a_option(exe->arg[i]))
	{
		i++;
		option = 0;
	}
	else
		option = 1;
	ft_echo(exe->arg, exe->argc, i, FALSE);
	if (option)
		printf("\n");
	return (0);
}
