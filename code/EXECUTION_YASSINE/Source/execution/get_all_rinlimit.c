/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/14 19:42:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

void	free_2str(char **s1, char **s2)
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

void	to_va_env(char **str, t_env *all_env)
{
	t_node	*n;
	t_node	*tmp;

	if (!str || !(*str))
		return ;
	n = NULL;
	str_to_node(*str, &n);
	tmp = n;
	while (tmp)
	{
		if (tmp->str[0] == '$')
			tmp->type_input = VA_ENV;
		tmp = tmp->next_node;
	}
	tmp = NULL;
	fusion_va(all_env, n, NULL);
	show_node(n);
	while (n && n->next_node)
		fusion_node(n, NON_DEFINI);
	free(*str);
	*str = NULL;
	*str = ft_strdup(n->str);
	free_all_node(n);
}

// Doit verifier au'il n a pas de \n et je dois gerer l'historique aussi
static char	*get_rinlimit(char *limit, int va_on, t_env *all_env)
{
	char	*tmp;
	char	*res;
	char	*input;

	input = readline("heredoc>>");
	if (ft_strcpm(limit, input) == 1)
		return (free_2str(&input, NULL), ft_strdup(""));
	if (va_on)
		to_va_env(&input, all_env);
	tmp = ft_strjoin(input, "\n");
	free_2str(&input, NULL);
	input = get_rinlimit(limit, va_on, all_env);
	res = ft_strjoin(tmp, input);
	free_2str(&tmp, &input);
	return (res);
}

// Je dois refaire le parssing rconcernant 
// le heredoc et les Variable denvironement
void	get_all_rinlimit(t_execute *all_exe, char *brut, t_env *all_env)
{
	t_redirecte	*rd;
	char		*res;

	(void) brut;
	while (all_exe)
	{
		rd = all_exe->all_rd;
		while (rd)
		{
			if (rd->type_rd == R_IN_LIMIT)
			{
				res = get_rinlimit(rd->str_file, rd->va_activate, all_env);
				free_2str(&(rd->str_file), NULL);
				rd->str_file = res;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
