/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilham_oua <ilham_oua@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:31 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/22 10:20:30 by ilham_oua        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef struct s_redirecte
{
	char				*str_file;
	t_type_input		type_rd;
	struct s_redirecte	*next;
	int					fd[2];
}	t_redirecte;

typedef struct s_execute
{
	size_t				index;
	const char			*cmd;
	const char			**arg;
	const char			**cmds;
	t_redirecte			*all_rd;
	t_redirecte			*last_out;
	t_redirecte			*last_in;
	int					fd[2];
	struct s_execute	*pip;
}	t_execute;

typedef struct s_node
{
	char			*str;
	struct s_node	*next_node;
	t_type_input	type_input;
	size_t			index;
}	t_node;

typedef struct s_prompt
{
	char	*invite;
	char	*brut;
	t_node	*all_cmd_line;
	int		err_parsing;
	int		nbr_of_pip;
	int		nbr_of_rd;
}	t_prompt;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next_va;
}	t_env;

typedef struct s_all_struct
{
	struct s_prompt	*prompte;
	t_execute		*exe;
	t_env			*all_va;
	int				err;
	int				prev;
	int				nb_cmds;
	pid_t			*pids;
	char			**env;
	char			*cmdpath;
}	t_all_struct;

#endif