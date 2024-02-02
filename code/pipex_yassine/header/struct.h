/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:05:44 by yatsu             #+#    #+#             */
/*   Updated: 2024/02/02 14:48:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./constante.h"

// je definie mes structure ici.

typedef struct s_cmd
{
	char	*argv;
	char	**cmd;
	char	*path;
	pid_t	pid;
}	t_cmd;

typedef struct s_file
{
	char	*path;
	int		fd;
}	t_file;

typedef struct s_pipex
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	t_file	*f1;
	t_file	*f2;
	char	**env;
	int		error;
	int		status;
	int		pipfd[2];
}	t_pipex;


typedef struct s_execute
{
	t_cmd	*cmd1;
	
	struct s_execute	*next;
}	t_execute;



typedef struct s_pipex_bonus
{
	t_execute	*all_cmd;
	t_file	*f1;
	t_file	*f2;
	char	**env;
	int		error;
	int		status;
	int		pipfd[2];
}	t_pipex_bonus;

#endif