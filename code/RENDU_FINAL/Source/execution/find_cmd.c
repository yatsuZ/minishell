/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:46:25 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/09 23:41:53 by yzaoui           ###   ########.fr       */
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

static char	*find_acces_path(char **all_path, char *cmd, t_all_struct **all)
{
	int		j;
	char	*path_cmd;

	j = 0;
	get_all_path(&all_path, all);
	path_cmd = NULL;
	while (all_path && all_path[j])
	{
		str_add(&path_cmd, all_path[j], 0);
		str_add(&path_cmd, "/", 0);
		str_add(&path_cmd, cmd, 0);
		if (access(path_cmd, F_OK) == 0)
			return (free_tab(&all_path), path_cmd);
		j++;
		free_2str(&path_cmd, NULL);
	}
	return (free_tab(&all_path), NULL);
}

char	*find_cmd2(char **all_path, char *cmd, t_all_struct **all)
{
	char	*path_cmd;

	if (cmd && ft_strchr(cmd, '/') && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	else if (!cmd || cmd[0] == '\0')
		return (NULL);
	path_cmd = find_acces_path(all_path, cmd, all);
	if (path_cmd)
		return (path_cmd);
	print_fd("command not found: ", 2);
	print_fd(cmd, 2);
	print_fd("\n", 2);
	return (free_tab(&all_path), NULL);
}
