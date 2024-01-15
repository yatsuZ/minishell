/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:12:13 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/15 10:13:33 by yzaoui           ###   ########.fr       */
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

size_t	is_space(char *str, size_t i)
{
	size_t	res;

	res = 0;
	if (!str[i])
		return (res);
	while (str[i + res] == ' ' || str[i + res] == '\t')
		res++;
	return (res);
}

t_boolean	have_space(char *s, size_t i)
{
	if (!s)
		return (FALSE);
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
		i++;
	if (s[i] == '\0')
		return (FALSE);
	return (TRUE);
}

t_boolean	have_nwl(char *s, size_t i)
{
	if (!s)
		return (FALSE);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (FALSE);
	return (TRUE);
}
