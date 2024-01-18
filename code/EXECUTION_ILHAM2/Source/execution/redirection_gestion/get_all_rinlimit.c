/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/18 17:14:09 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

static void	add_input_to_history(char *str, char **hs)
{
	rl_clear_history();
	if ((*hs)[ft_strlen(*hs) - 1] != '\n')
		str_add(hs, "\n", 0);
	str_add(hs, str, 0);
	add_history(*hs);
}

static char	*get_rinlimit(t_redirecte *rd, t_env *all_env, char **hs);

static char	*add_new_input(char *input, t_redirecte *rd, t_env *env, char **hs)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(input, "\n");
	add_input_to_history(tmp, hs);
	if (rd->va_activate)
		str_change_env(&input, env);
	free_2str(&input, NULL);
	input = get_rinlimit(rd, env, hs);
	res = ft_strjoin(tmp, input);
	free_2str(&tmp, &input);
	return (res);
}

static char	*multi_line(char *str, t_redirecte *rd, t_env *env, char **hs)
{
	char	*res;
	t_node	*n;

	n = NULL;
	str_to_node_nwl(str, &n);
	if (n && ft_strcpm(rd->str_file, n->str) == 1)
		return (free_2str(&str, NULL), free_node(n), ft_strdup(""));
	while (n && n->next_node)
	{
		if (ft_strcpm(rd->str_file, n->next_node->str) == 1)
		{
			res = ft_strdup(n->str);
			add_input_to_history(res, hs);
			add_input_to_history(n->next_node->str, hs);
			if (rd->va_activate)
				str_change_env(&res, env);
			return (free_node(n), free_2str(&str, NULL), res);
		}
		fusion_node(n, -1);
	}
	return (free_node(n), add_new_input(str, rd, env, hs));
}

// Doit verifier au'il n a pas de \n et je dois gerer l'historique aussi
static char	*get_rinlimit(t_redirecte *rd, t_env *all_env, char **hs)
{
	char	*input;

	input = readline("heredoc>>");
	if (have_nwl(input, 0))
		return (multi_line(input, rd, all_env, hs));
	if (ft_strcpm(rd->str_file, input) == 1)
	{
		add_input_to_history(input, hs);
		return (free_2str(&input, NULL), ft_strdup(""));
	}
	return (add_new_input(input, rd, all_env, hs));
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
				res = get_rinlimit(rd, all_env, brut);
				free_2str(&(rd->str_file), NULL);
				rd->str_file = res;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
