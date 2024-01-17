/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:23:17 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/17 11:48:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

//partie importante je vais juste moccupe des builtin
int	ft_exec(t_execute *exe, t_all_struct **all)
{
	if (!all || !(*all) || !exe)
		return (STATUS);
	// faire lkes builtins
	return (ft_exec(exe->pip, all));
}
