/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/14 01:17:30 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	free_str(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

static char	*add_nwl(char *str)
{
	char	*new;

	new = ft_strjoin(str, "\n");
	free_str(&str, NULL);
	return (new);
}

static char	*get_rinlimit(char *limit, char *history, int va_on)
{
	char	*res;
	char	*input;
	char	*fusion;

	add_history(history);
	input = readline("heredoc>>");
	if (ft_strcpm_last_nwl(limit, &input, history, va_on) == TRUE)// doit verifier aue tout est bon prendre en compte juste le dernier \n et remplace le va par leur val si va on
	{
		rl_clear_history();
		return (ft_strdup("\n"));
	}
	res = add_nwl(input);
	fusion = ft_strjoin(history, res);
	add_history(fusion);
	input = get_rinlimit(limit, fusion, va_on);
	free_str(&res, NULL);
	res = ft_strjoin(fusion, input);
	return (free_str(&input, &fusion), res);
}

// Je dois refaire le parssing rconcernant 
// le heredoc et les Variable denvironement
void	get_all_rinlimit(t_execute *all_exe, char *brut)
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
				res = get_rinlimit(rd->str_file, brut, rd->va_activate);
				free(rd->str_file);
				rd->str_file = NULL;
				rd->str_file = res;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
