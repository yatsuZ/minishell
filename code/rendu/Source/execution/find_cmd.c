/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:46:25 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/29 19:41:58 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

static void	get_all_path(char ***all_path, t_all_struct **all)
{
	char	*cmd_path;

	cmd_path = get_value((*all)->all_va, "PATH", 0);
	*all_path = ft_split(cmd_path, ':');
	free_2str(&cmd_path, NULL);
}

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int find_cmd(char **all_path, char **cmd, t_all_struct **all)
{
	int		j;
	char	*path_cmd;

	j = 0;
	if (!cmd || !(*cmd))
		return (0);
	if (ft_strchr(*cmd, '/'))
		return (1);
	get_all_path(&all_path, all);
	path_cmd = NULL;
	while (all_path && all_path[j])
	{
		str_add(&path_cmd, all_path[j], 0);
		str_add(&path_cmd, "/", 0);
		str_add(&path_cmd, (*cmd), 0);
		if (access(path_cmd, F_OK) == 0)
			return (free_2str(cmd, NULL), *cmd = path_cmd, free_tab(&all_path), 1);
		j++;
		free_2str(&path_cmd, NULL);
	}
	print_fd("command not found: ", 2);
	print_fd((*cmd), 2);
	print_fd("\n", 2);
	return (free_tab(&all_path), 0);
}
