/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:31:29 by ilouacha          #+#    #+#             */
/*   Updated: 2024/01/22 17:28:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../Header/Minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	len_s;
	unsigned int	i;
	char			*z;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if ((start > len_s) || (len_s == 0))
		return (ft_strdup(""));
	i = 0;
	while ((i < len) && (i < (len_s - start)))
		i++;
	z = malloc(sizeof(*z) * (i + 1));
	if (!z)
		return (NULL);
	i = 0;
	while ((i < len) && (i < (len_s - start)))
	{
		z[i] = s[start + i];
		i++;
	}
	z[i] = '\0';
	return (z);
}
