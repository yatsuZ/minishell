/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 23:06:33 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/26 09:46:29 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/Minishell.h"

size_t	is_separator(char *str, size_t i)
{
	size_t	res;

	res = 0;
	if (!str[i])
		return (res);
	if ((str[i] == '>' && str[i + 1] == '>') || \
	(str[i] == '<' && str[i + 1] == '<'))
		return (2);
	while (str[i + res] == ' ' || str[i + res] == '\t')
	{
		res++;
	}
	if (str[i] == '>' || str[i] == '<' || str[i] == '\'' \
	|| str[i] == '\"' || str[i] == '|' || str[i] == '$')
		return (1);
	return (res);
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

int	get_all_input(t_prompt *promp)
{
	promp->brut = readline(promp->invite);
	printf("%s\n", )
	str_to_node(promp->brut, &(promp->all_cmd_line));
	return (0);
}
