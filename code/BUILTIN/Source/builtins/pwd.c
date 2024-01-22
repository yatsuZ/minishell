/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:56:28 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/21 23:31:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

int	exec_pwd(t_execute *exe, t_all_struct **all)
{
	char	*pwd_msg;

	(void) all;
	(void) exe;
	pwd_msg = getcwd(NULL, 0);
	if (pwd_msg == NULL)
		return (print_fd("ERROR pour recuperation du pwd\n", 2), 1);
	printf("%s\n", pwd_msg);
	free_2str(&pwd_msg, NULL);
	return (0);
}
