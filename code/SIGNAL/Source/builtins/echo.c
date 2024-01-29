/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/23 20:15:17 by yzaoui           ###   ########.fr       */
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

int	exec_echo(t_execute *exe, t_all_struct **all)
{
	(void) all;
	size_t	i;
	int		option;

	i = 0;
	if (exe->arg == NULL)
		return(printf("\n"), 0);
	option = 1;
	while (i < exe->nbr_of_arg)
	{
		if (!i && is_a_option(exe->arg[i]))
			option = 0;
		else
		{
			if (exe->arg[i])
			printf("%s", exe->arg[i]);
			if ( exe->arg[i + 1] != NULL)
				printf(" ");
		}
		i++;
	}
	if (option)
		printf("\n");
	return (0);
}
