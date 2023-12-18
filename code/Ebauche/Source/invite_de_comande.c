/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite_de_comande.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 02:13:16 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/18 01:13:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/Minishell.h"


size_t	is_separator(char *str, size_t i)
{
	size_t	res;

	res = 0;
	while (str[i + res] == ' ')
		res++;
	if (res)
		return (res);
	while (str[i + res] == '\t')
		res++;
	if (res)
		return (res);
	if (str[i] == '>' || str[i] == '<')
		res++;
	if (res)
		return (res);
	return(res);
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

int	get_invite_de_comande(t_prompt *promp)
{
	char	*input;

	input = readline(promp->invite);
	str_to_node(input, &(promp->all_cmd_line));
	free(input);
	input = NULL;
	return (0);
}
