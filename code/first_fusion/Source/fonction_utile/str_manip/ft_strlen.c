/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:45:22 by yzaoui            #+#    #+#             */
/*   Updated: 2024/01/20 18:09:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Header/Minishell.h"

size_t	ft_strlen(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0')
		i++;
	return (i);
}

void	free_2str(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

int	print_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}