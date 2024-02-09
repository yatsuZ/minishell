/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 00:59:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

long long	is_numeric2(char *str, size_t i, int *err)
{
	long long	nbr;

	nbr = 0;
	if (!str || str[i] == '\0')
		return (*err = -1, 0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[0] == '-')
		{
			nbr = nbr * 10 - (str[i] - '0');
			if (nbr > 0)
				return (*err = -2, 0);
		}
		else
		{
			nbr = nbr * 10 + (str[i] - '0');
			if (nbr < 0)
				return (*err = -3, 0);
		}
		i++;
	}
	if (str[i] != '\0')
		return (*err = -4, 0);
	return (nbr);
}

int	str_to_modul255(char *str, size_t i)
{
	long long	nbr;
	int			err;

	err = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nbr = is_numeric2(str, i, &err);
	if (err)
		return (-2);
	if (str[0] == '-' && nbr != 0)
		return (256 + (nbr % 256));
	return (nbr % 256);
}

static int	get_res(char **arg, size_t ac, t_boolean *many_arg, int status)
{
	size_t	i;
	size_t	nbr_of_arg;
	int		res;

	i = 1;
	nbr_of_arg = 0;
	res = status;
	while (arg && i < ac)
	{
		if (!nbr_of_arg && arg[i])
		{
			res = str_to_modul255(arg[i], 0);
			nbr_of_arg++;
		}
		else if (arg[i] && nbr_of_arg)
			return (*many_arg = TRUE, res);
		i++;
	}
	return (res);
}

int	exec_exit(t_execute *exe, t_all_struct **all)
{
	t_boolean	many_arg;
	char		*first_arg;

	printf("exit\n");
	many_arg = FALSE;
	(*all)->status = get_res(exe->arg, exe->argc, &many_arg, (*all)->status);
	if ((*all)->status == -2)
	{
		(*all)->status = 2;
		first_arg = get_first_arg_no_null(exe->arg, exe->argc, 1, &((*all)->err));
		if ((*all)->err)
			end(*all);
		print_fd("bash: exit: ", 2);
		print_fd(first_arg, 2);
		free_2str(&first_arg, NULL);
		print_fd(": numeric argument required\n", 2);
		end(*all);
	}
	if (many_arg)
	{
		print_fd("bash: exit: too many arguments\n", 2);
		return ((*all)->status = 1, 1);
	}
	return (end(*all), 0);
}
