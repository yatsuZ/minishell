/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:45:26 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/04 13:55:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

void	index_update(t_node *n)
{
	t_node	*index_n;
	int		i;

	if (!n)
		return ;
	i = n->index;
	index_n = n->next_node;
	while (index_n)
	{
		index_n->index = i + 1;
		index_n = index_n->next_node;
		i++;
	}
}

void	del_next_node(t_node *n)
{
	t_node	*new_n;

	if (n == NULL || n->next_node == NULL)
		return ;
	new_n = n->next_node->next_node;
	n->next_node->next_node = NULL;
	free_node(n->next_node);
	n->next_node = new_n;
	index_update(n);
}

void	fusion_node(t_node *n, int new_type)
{
	char	*new_str;

	if (n->next_node == NULL)
		return ;
	new_str = ft_strjoin(n->str, n->next_node->str);
	free(n->str);
	n->str = NULL;
	n->str = new_str;
	del_next_node(n);
	if (new_type != -1)
		n->type_input = new_type;
}

void	str_to_node(char *str, t_node **res)
{
	size_t	i_start;
	size_t	i_end;

	if (!str)
		return ;
	i_end = 0;
	i_start = 0;
	while (str[i_end])
	{
		if (is_separator(str, i_end) != 0)
		{
			i_start = i_end;
			i_end = i_end + is_separator(str, i_start);
			add_last_node(res, ft_strcut(str, i_start, i_end));
		}
		if (is_separator(str, i_end) == 0 && str[i_end])
		{
			i_start = i_end;
			while (is_separator(str, i_end) == 0 && str[i_end])
				i_end++;
			add_last_node(res, ft_strcut(str, i_start, i_end));
			i_start = i_end;
		}
	}
}

void	str_to_node_nwl(char *str, t_node **res)
{
	size_t	i_start;
	size_t	i_end;

	if (!str)
		return ;
	i_end = 0;
	i_start = 0;
	while (str[i_end])
	{
		if (str[i_end] == '\n')
		{
			i_start = i_end;
			i_end = i_end + 1;
			add_last_node(res, ft_strcut(str, i_start, i_end));
		}
		if (str[i_end] != '\n' && str[i_end])
		{
			i_start = i_end;
			while (str[i_end] != '\n' && str[i_end])
				i_end++;
			add_last_node(res, ft_strcut(str, i_start, i_end));
			i_start = i_end;
		}
	}
}
