/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/15 09:32:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

// Doit verifier au'il n a pas de \n et je dois gerer l'historique aussi
static char	*get_rinlimit(char *limit, int va_on, t_env *all_env, char **hs)
{
	char	*tmp;
	char	*res;
	char	*input;

	input = readline("heredoc>>");
	if (ft_strcpm(limit, input) == 1)
		return (free_2str(&input, NULL), ft_strdup(""));
	rl_clear_history();
	if (va_on)
		str_change_env(&input, all_env);
	tmp = ft_strjoin(input, "\n");
	if ((*hs)[ft_strlen(*hs) - 1] != '\n')
		str_add(hs, "\n", 0);
	str_add(hs, tmp, 0);
	add_history(*hs);
	free_2str(&input, NULL);
	input = get_rinlimit(limit, va_on, all_env, hs);
	res = ft_strjoin(tmp, input);
	free_2str(&tmp, &input);
	return (res);
}

// Je dois refaire le parssing rconcernant 
// le heredoc et les Variable denvironement
void	get_all_rinlimit(t_execute *all_exe, char **brut, t_env *all_env)
{
	t_redirecte	*rd;
	char		*res;

	while (all_exe)
	{
		rd = all_exe->all_rd;
		while (rd)
		{
			if (rd->type_rd == R_IN_LIMIT)
			{
				res = get_rinlimit(rd->str_file, rd->va_activate, all_env, brut);
				free_2str(&(rd->str_file), NULL);
				rd->str_file = res;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
