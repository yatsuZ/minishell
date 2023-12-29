/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:12:13 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/29 20:08:09 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	type_of_str(char c)
{
	if (c == '\'')
		return (SINGLE_COTE);
	else if (c == '\"')
		return (DOUBLE_COTE);
	else if (c == ' ' || c == '\t')
		return (SEPARATOR);
	else if (c == '$')
		return (VA_ENV);
	else if (c == '<')
		return (R_IN);
	else if (c == '>')
		return (R_OUT);
	else if (c == '<' && c == '<')
		return (R_IN_LIMIT);
	else if (c == '>' && c == '>')
		return (R_OUT_ADD);
	else if (c == '|')
		return (PIP);
	return (-2);
}

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
	|| str[i] == '\"' || str[i] == '|' || str[i] == '$' \
	|| str[i] == '\\')
		return (1);
	return (res);
}
