/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 11:17:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static long long	is_numeric2(char *str, size_t i, int *err)
{
	long long	nbr;

	nbr = 0;
	if (str[i] == '\0')
		return (*err = -2, 0);
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
				return (*err = -2, 0);
		}
		i++;
	}
	if (str[i] != '\0')
		return (*err = -2, 0);
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
	if (err == -2)
		return (-2);
	if (str[0] == '-' && nbr != 0)
		return (256 - (nbr % 256));
	return (nbr % 256);
}

int	exec_exit(t_execute *exe, t_all_struct **all)
{
	int		res;
	char	*msg;
	
	printf("exit\n");
	if (exe->arg && exe->arg[1] != NULL)
	{
		print_fd("bash: exit: too many arguments\n", 2);
		return (1);
	}
	if (!exe->arg)
		res = g_status;
	else
		res = str_to_modul255(exe->arg[0], 0);
	if (res == -2)
	{
		msg = ft_strjoin("bash: exit: ", exe->arg[0]);
		str_add(&msg, ": numeric argument required\n", 0);
		g_status = res * -1;
		print_fd(msg, 2);
		free_2str(&msg, NULL);
		end(*all);
	}
	end(*all);
	return (0);
}
