/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:45:22 by yzaoui            #+#    #+#             */
/*   Updated: 2023/12/15 11:14:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/Minishell.h"

size_t	ft_strlen(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0')
	{
		i++;
	}
	return (i);
}