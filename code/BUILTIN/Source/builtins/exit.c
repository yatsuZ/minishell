/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:59:44 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/20 18:17:12 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"
// LLONG_MIN
// LLONG_MAX
// long long
int	is_numeric(char *str)
{
	unsigned long long	nbr;
	size_t				i;

	i = 0;
	nbr = 0;
	if (!str)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (-2);
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && nbr <= LONG_MAX)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' || nbr > LONG_MAX)
		return (-2);
	if (str[0] == '-')
		nbr = nbr * -1;
	return ((int) (nbr % 255));
	
}

int	exec_exit(t_execute *exe, t_all_struct **all)
{
	int		res;
	char	*msg;
	
	printf("exit\n");
	if (!(exe->arg == NULL || exe->arg[0] == NULL || exe->arg[1] == NULL))
	{
		print_fd("bash: exit: too many arguments\n", 2);
		return (1);
	}
	res = is_numeric(exe->arg[0]);
	if (res == -2)
	{
		msg = ft_strjoin("bash: exit: ", exe->arg[0]);
		str_add(&msg, ": numeric argument required\n", 0);
		g_status = res * -1;
		print_fd(msg, 2);
		free_2str(&msg, NULL);
		end(*all);
	}
	if (res != -1)
		g_status = res;
	end(*all);
	return (0);
}
