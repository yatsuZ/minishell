/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <ilouacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:31 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/15 18:52:39 by ilouacha         ###   ########.fr       */
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
}	t_redirecte;

typedef struct s_execute
{
	const char			*cmd;
	const char			**arg;
	const char			cmds;// cmds = {&cmd, arg};
	t_redirecte			*all_rd;
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
}	t_all_struct;

/* je rajoute un tableau cmds dans data
char	**cmds = {(*char *)cmd, (char **)arg}
*/
typedef struct s_data
{
	char		**env;
	pid_t		*pids;
	int			fd[2];
	int			prev;
	char		**cmds;
	char		*cmdpath;
	int			nb_cmd;
	char		*infile;
	char		*outfile;
	int			len;
	char		*limiter;
	int			fd_h;
	int			here_doc;
	int			j;
}		t_data;

#endif