/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:12:13 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/24 17:57:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

int	type_of_str(char *s)
{
	if (!s)
		return (-1);
	else if (s[0] == '\'')
		return (SINGLE_COTE);
	else if (s[0] == '\"')
		return (DOUBLE_COTE);
	else if (s[0] == ' ' || s[0] == '\t')
		return (SEPARATOR);
	else if (s[0] == '$')
		return (VA_ENV);
	else if (s[0] == '<')
		return (R_IN);
	else if (s[0] == '>')
		return (R_OUT);
	else if (s[0] == '<' && s[1] == '<')
		return (R_IN_LIMIT);
	else if (s[0] == '>' && s[1] == '>')
		return (R_OUT_ADD);
	else if (s[0] == '|')
		return (PIP);
	return (-2);
}

int	is_str_or_cote(int type)
{
	return (type == STR || type == SINGLE_COTE || type == DOUBLE_COTE);
}
