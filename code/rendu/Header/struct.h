/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:31 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/02 19:43:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef struct s_redirecte
{
	char				*str_file;
	t_type_input		type_rd;
	int					va_activate;
	int					fd;
	int					error;
	struct s_redirecte	*next;
}	t_redirecte;

typedef struct s_execute
{
	int					index;
	char				*cmd;
	char				**arg;
	size_t				argc;
	t_redirecte			*all_rd;
	int					*fd;
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
	t_boolean		show;
	struct s_env	*next_va;
}	t_env;

typedef struct s_all_struct
{
	struct s_prompt	*prompte;
	t_execute		*exe;
	t_env			*all_va;
	int				prev;
	int				nb_cmds;
	pid_t			*pids;
	char			**env;
	int				status;
	int				err;
}	t_all_struct;

#endif