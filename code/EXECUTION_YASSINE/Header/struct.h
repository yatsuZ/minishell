/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:31 by yzaoui            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/11 00:05:27 by yzaoui           ###   ########.fr       */
=======
/*   Updated: 2024/01/11 19:28:30 by yzaoui           ###   ########.fr       */
>>>>>>> c5bf03d7a8726330b3b27ff6a26e9f85e24a275e
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
	char				*cmd;
	char				**arg;
	t_redirecte			*all_rd;
	int					fd_in;
	int					fd_out;
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

#endif