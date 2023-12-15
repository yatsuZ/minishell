/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:20:31 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 12:36:37 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef enum {
	false,
	true
} bool;

typedef struct s_node
{
	char	*str;
	struct s_node	*next_node;
}	t_node;

typedef struct s_prompt
{
	char	*invite;
	t_node	*all_cmd_line;
	bool	end_of_prompt;
}	t_prompt;

typedef struct s_all_struct
{
	struct s_prompt	*prompte;
	int			err;
} t_all_struct;

#endif