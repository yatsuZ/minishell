/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:57:47 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 11:01:20 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// char	*all_va_to_char_for_export(t_env *all_va)
// {
// 	char	*str;
// 	char	*next_str;

// 	if (!all_va)
// 		return (ft_strdup(""));
// 	str = ft_strjoin(all_va->key, "=");
// 	str_add(&str, all_va->value, 0);
// 	next_str = all_va_to_char(all_va->next_va);
// 	str_add(&str, "\n", 0);
// 	if (!next_str)
// 		return (str);
// 	str_add(&str, next_str, 1);
// 	next_str = NULL;
// 	return (str);
// }

int	exec_export(t_execute *exe, t_all_struct **all)
{
	// char	*msg;

	if (exe->arg != NULL)
		printf("PAS DARGUmENT\n");
	(void) all;
	show_execute(exe, 0);
	printf("Je dois faire la commande export\n");
	return (0);
}
