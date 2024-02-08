/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:13:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/07 14:23:41 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

static size_t	nbr_of_char(int nbr)
{
	if (nbr == INT_MIN)
		return (1 + nbr_of_char(INT_MAX));
	if (nbr < 0)
		return (1 + nbr_of_char(nbr * -1));
	if (nbr < 10)
		return (1);
	return (1 + nbr_of_char(nbr / 10));
}

static void	change_str(char *str, int nbr, size_t i)
{
	if (!str)
		return ;
	if (nbr < 0)
	{
		str[0] = '-';
		change_str(str, nbr * -1, i);
	}
	else if (nbr < 10)
		str[--i] = nbr + '0';
	else
	{
		str[--i] = (nbr % 10) + '0';
		change_str(str, nbr / 10, i);
	}
}

char	*int_to_str(int nbr)
{
	size_t	nbr_c;
	char	*str;

	if (nbr == INT_MAX)
		return (ft_strdup("2147483647"));
	else if (nbr == INT_MIN)
		return (ft_strdup("-2147483648"));
	nbr_c = nbr_of_char(nbr);
	str = ft_calloc(nbr_c + 1, sizeof(char));
	change_str(str, nbr, nbr_c);
	return (str);
}
