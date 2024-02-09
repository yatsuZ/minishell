/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_rinlimit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:21:40 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 00:25:31 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

static char	*get_rinlimit(t_redirecte *rd, t_all_struct *all);

static char	*add_new_input(char *input, t_redirecte *rd, t_all_struct *all)
{
	char	*tmp;
	char	*res;
	t_env	*env;

	env = all->all_va;
	if (rd->va_activate)
		str_change_env(&input, env, all->status, &(all->err));
	tmp = ft_strjoin(input, "\n", &(all->err));
	free_2str(&input, NULL);
	if (all->err)
		end(all);
	input = get_rinlimit(rd, all);
	res = ft_strjoin(tmp, input, &(all->err));
	free_2str(&tmp, &input);
	return (res);
}

char	*multi_line2(t_node *n, char *str, t_redirecte *rd, t_all_struct *all)
{
	char	*res;

	while (n && n->next_node)
	{
		if (ft_strcpm(rd->str_file, n->next_node->str) == 1)
		{
			res = ft_strdup(n->str, &(all->err));
			if (all->err == 0 && rd->va_activate)
				str_change_env(&res, all->all_va, all->status, &(all->err));
			if (all->err)
				return (free_2str(&str, NULL), free_node(n), end(all), res);
			return (free_2str(&str, NULL), free_node(n), res);
		}
		fusion_node(n, -1, &(all->err));
		if (all->err)
			return (free_2str(&str, NULL), free_node(n), end(all), res);
	}
	return (free_node(n), add_new_input(str, rd, all));
}

static char	*multi_line(char *str, t_redirecte *rd, t_all_struct *all)
{
	char	*res;
	t_node	*n;

	n = NULL;
	str_to_node_nwl(str, &n, &(all->err));
	if (all->err)
		end(all);
	if (n && ft_strcpm(rd->str_file, n->str) == 1)
	{
		res = ft_strdup("", &(all->err));
		if (all->err)
			return (free_2str(&str, NULL), free_node(n), end(all), res);
		return (free_2str(&str, NULL), free_node(n), res);
	}
	return (multi_line2(n, str, rd, all));
}

static char	*get_rinlimit(t_redirecte *rd, t_all_struct *all)
{
	char	*input;
	char	*tmp;

	input = readline("heredoc>>");
	if (have_nwl(input, 0))
		return (multi_line(input, rd, all));
	if (ft_strcpm(rd->str_file, input) == 1)
	{
		free_2str(&input, NULL);
		tmp = ft_strdup("", &(all->err));
		if (all->err)
			return (free_2str(&tmp, NULL), end(all), NULL);
		return (tmp);
	}
	return (add_new_input(input, rd, all));
}

void	get_all_rinlimit(t_execute *all_exe, t_all_struct *all)
{
	t_redirecte	*rd;
	char		*res;

	rd = NULL;
	while (all_exe)
	{
		rd = all_exe->all_rd;
		while (rd)
		{
			if (rd->type_rd == R_IN_LIMIT)
			{
				res = get_rinlimit(rd, all);
				free_2str(&(rd->str_file), NULL);
				rd->str_file = res;
			}
			rd = rd->next;
		}
		all_exe = all_exe->pip;
	}
}
